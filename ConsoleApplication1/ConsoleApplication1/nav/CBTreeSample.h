#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>

#include "../DuktapeRunner.h"


class CWorldContext
{
public:
	static bool bIsOpenDoor;
	static int doorPos;
	static int keyPos;

	static duk_ret_t __get_is_door_open(duk_context *ctx);
	static duk_ret_t __get_door_position(duk_context *ctx);
	static duk_ret_t __get_key_position(duk_context *ctx);

	static void register_duck(duk_context *ctx);
};

class CNPCContext
{
public:
	static bool bHasKey;
	static int pos;

	static duk_ret_t __get_has_key(duk_context *ctx);
	static duk_ret_t __get_position(duk_context *ctx);
	static duk_ret_t __do_move(duk_context *ctx);
	static duk_ret_t __do_take_key(duk_context *ctx);
	static duk_ret_t __do_open_door(duk_context *ctx);

	static void register_duck(duk_context *ctx);
};


//----------------------------------------

class IBTNode
{
public:
	virtual void run() = 0;
};

class CRTLeaf : public IBTNode
{
};

class CRTSelector : public IBTNode
{
private:
	IBTNode *onTrue = nullptr;
	IBTNode *onFalse = nullptr;
public:
	bool bJustExit;
	virtual ~CRTSelector();

	void setOnTrue( IBTNode *toSet );
	void setOnFalse( IBTNode *toSet );

	virtual bool doRunTest () = 0;
	virtual void run() override;
};

class CRTSequence : public IBTNode
{
private:
	std::vector<IBTNode*> nodeList;
public:
	virtual ~CRTSequence();

	void addNode ( IBTNode *toAdd );

	virtual void run() override;
};
//----------------------------

class CBTScriptSelector : public CRTSelector
{
public:
	DuktapeRunner dk;
	bool bIsTrueOrFalse;
	
	CBTScriptSelector( const char* script );
	virtual ~CBTScriptSelector();

	virtual bool doRunTest () override;


public:
	static CBTScriptSelector* _this;
	static duk_ret_t __set_just_exit(duk_context *ctx);
	static duk_ret_t __set_true_or_false(duk_context *ctx);
};

class CBTScriptLeaf : public CRTLeaf
{
public:
	DuktapeRunner dk;

	CBTScriptLeaf( const char* script );
	virtual ~CBTScriptLeaf();

	virtual void run() override;
};





class CBTMain
{
public:
	void doRun();
};