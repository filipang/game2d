#include "CBTreeSample.h"




bool CWorldContext::bIsOpenDoor = false;
int CWorldContext::doorPos = 3;
int CWorldContext::keyPos = -3;

duk_ret_t CWorldContext::__get_is_door_open(duk_context *ctx)
{
	if ( bIsOpenDoor )
		 duk_push_true(ctx);
	else duk_push_false(ctx);
	return 1;
}
duk_ret_t CWorldContext::__get_door_position(duk_context *ctx)
{
	duk_push_number(ctx, doorPos);
	return 1;
}
duk_ret_t CWorldContext::__get_key_position(duk_context *ctx)
{
	duk_push_number(ctx, keyPos);
	return 1;
}
void CWorldContext::register_duck(duk_context *ctx)
{
	duk_push_c_function(ctx, __get_is_door_open, 0);
	duk_put_prop_string(ctx, -2, "isDoorOpen");
	duk_push_c_function(ctx, __get_door_position, 0);
	duk_put_prop_string(ctx, -2, "getDoorPos");
	duk_push_c_function(ctx, __get_key_position, 0);
	duk_put_prop_string(ctx, -2, "getKeyPos");
}

bool CNPCContext::bHasKey = false;
int CNPCContext::pos = 0;

duk_ret_t CNPCContext::__get_has_key(duk_context *ctx)
{
	if ( bHasKey )
		 duk_push_true(ctx);
	else duk_push_false(ctx);
	return 1;
}
duk_ret_t CNPCContext::__get_position(duk_context *ctx)
{
	duk_push_number(ctx, pos);
	return 1;
}
duk_ret_t CNPCContext::__do_move(duk_context *ctx)
{
	int moveBy = duk_require_int(ctx, 0);
	pos += moveBy;
	duk_push_true(ctx);
	return 1;
}
duk_ret_t CNPCContext::__do_take_key(duk_context *ctx)
{
	bHasKey = true;
	duk_push_true(ctx);
	return 1;
}

duk_ret_t CNPCContext::__do_open_door(duk_context *ctx)
{
	CWorldContext::bIsOpenDoor = true;
	duk_push_true(ctx);
	return 1;
}

void CNPCContext::register_duck(duk_context *ctx)
{
	duk_push_c_function(ctx, __get_has_key, 0);
	duk_put_prop_string(ctx, -2, "npcHasKey");
	duk_push_c_function(ctx, __get_position, 0);
	duk_put_prop_string(ctx, -2, "getNpcPos");
	duk_push_c_function(ctx, __do_move, 1);
	duk_put_prop_string(ctx, -2, "doNpcMove");
	duk_push_c_function(ctx, __do_take_key, 0);
	duk_put_prop_string(ctx, -2, "doTakeKey");
	duk_push_c_function(ctx, __do_open_door, 0);
	duk_put_prop_string(ctx, -2, "doOpenDoor");
}


//----------------------------------

CRTSelector::~CRTSelector()
{
	delete onTrue;
	delete onFalse;
}
void CRTSelector::setOnTrue( IBTNode *toSet )
{
	if ( onTrue ) delete onTrue;
	onTrue = toSet;
}
void CRTSelector::setOnFalse( IBTNode *toSet )
{
	if ( onFalse ) delete onFalse;
	onFalse = toSet;
}
void CRTSelector::run()
{
	bJustExit = false;
	bool bresult = doRunTest();
	if ( bJustExit )
		return;

	if ( bresult )
	{
		if ( onTrue )
			onTrue->run();
	}
	else 
	{
		if ( onFalse )
			onFalse->run();
	}
}
//----------------------

CRTSequence::~CRTSequence()
{
	for ( auto node : nodeList )
		delete node;
	nodeList.clear();
}
void CRTSequence::addNode(IBTNode *toAdd)
{
	nodeList.push_back ( toAdd );
}
void CRTSequence::run()
{
	for ( auto node : nodeList )
		node->run();
}
//-----------------------------
CBTScriptSelector* CBTScriptSelector::_this = nullptr;

CBTScriptSelector::CBTScriptSelector(const char* script)
{
	bIsTrueOrFalse = false;

	CWorldContext::register_duck ( dk._ctx );
	CNPCContext::register_duck ( dk._ctx );
	duk_push_c_function(dk._ctx, __set_just_exit, 1);
	duk_put_prop_string(dk._ctx, -2, "setJustExit");
	duk_push_c_function(dk._ctx, __set_true_or_false, 1);
	duk_put_prop_string(dk._ctx, -2, "setTrueOrFalse");

	dk.push_file_as_string_and_eval ( script );
}
CBTScriptSelector::~CBTScriptSelector()
{

}

bool CBTScriptSelector::doRunTest()
{
	_this = this;
	bIsTrueOrFalse = false;
	bJustExit = false;

	dk.run_duktape ( "run" );
	_this = nullptr;
	return bIsTrueOrFalse;
}

duk_ret_t CBTScriptSelector::__set_just_exit(duk_context *ctx)
{
	bool isTrue = duk_require_boolean(ctx, 0);
	_this->bJustExit = isTrue;
	duk_push_true(ctx);
	return 1;

}
duk_ret_t CBTScriptSelector::__set_true_or_false(duk_context *ctx)
{
	bool isTrue = duk_require_boolean(ctx, 0);
	_this->bIsTrueOrFalse = isTrue;
	duk_push_true(ctx);
	return 1;
}

CBTScriptLeaf::CBTScriptLeaf(const char* script)
{
	CWorldContext::register_duck ( dk._ctx );
	CNPCContext::register_duck ( dk._ctx );

	dk.push_file_as_string_and_eval ( script );
}
CBTScriptLeaf::~CBTScriptLeaf()
{

}
void CBTScriptLeaf::run()
{	
	dk.run_duktape ( "run" );
}


void CBTMain::doRun()
{
	IBTNode* root = nullptr;

	//----- start build tree
	CBTScriptSelector* keySelect = new CBTScriptSelector( "keySelect.js" );
	keySelect->setOnTrue ( new CBTScriptLeaf( "takeKey.js" ) );
	keySelect->setOnFalse ( new CBTScriptLeaf( "goToKey.js" ) );

	CBTScriptSelector* doorSelect = new CBTScriptSelector("doorSelect.js");
	doorSelect->setOnTrue ( new CBTScriptLeaf( "openDoor.js" ) );
	doorSelect->setOnFalse ( new CBTScriptLeaf( "goToDoor.js" ) );

	CRTSequence* rootSq = new CRTSequence(); root = rootSq;
	rootSq->addNode ( keySelect );
	rootSq->addNode ( doorSelect );
	//----- end build tree

	while ( CWorldContext::bIsOpenDoor == false )// condition based on state
	{
		root->run();
	}

	printf ( "abracadabra");
}