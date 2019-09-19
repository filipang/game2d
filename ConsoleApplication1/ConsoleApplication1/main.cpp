// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"
#include "Entity.h"
#include "Game.h"

/*
class IResourceSink
{
public:
	virtual void OnDestroy(class Resource*) = 0;
};
class IRefCounted
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};

template<class sink>
class SinkContainer
{
protected:
	std::vector<sink*> _sinks;
	void AddSink(sink* a) { _sinks.push_back(a); }
	void RemoveSink(sink* a)
	{
		auto it = std::find(_sinks.begin(), _sinks.end(), a);
		if (it != _sinks.end())
			_sinks.erase(it);
	}
};

class Resource : SinkContainer<IResourceSink>, IRefCounted
{
	int ref = 0;
public:
	void RegisterSink(IResourceSink *o) { AddSink(o); }
	void UnregisterSink(IResourceSink *o) { RemoveSink(o); }
	// from IRefCounted
	virtual void AddRef() override { ref++; }
	virtual void Release() override
	{
		ref--;
		if (ref == 0)
			for (auto* sink : _sinks)
				sink->OnDestroy(this);
		delete this;
	}
};



class ResourceMgr : public IResourceSink
{
	std::vector<Resource*> _atlasses;

public:
	virtual void OnDestroy(class Resource* r) override
	{
		auto it = std::find(_atlasses.begin(), _atlasses.end(), r);
		if (it != _atlasses.end())
			_atlasses.erase(it);
	}
	void AddResource(Resource* a)
	{
		_atlasses.push_back(a);
		a->RegisterSink(this);
	}
};

ResourceMgr rmg;
Resource* createResource()
{
	auto *a = new Resource();
	rmg.AddResource(a);
	return a;
}*/

/*
class cell
{
public:
	unsigned int _flags; //( block, water, ground,  )
	class IDynamicObj* _dobj;
	int resid;
};
class DynObj
{
	int footprint[4];
	int pos[2];

	std::vector<cell*> _cells;
	buildCells()
	{
		for ( int x = pos[0] + footprint[0] ; x <= pos[0] + footprint[1] ; ++x )
			for (int y = pos[1] + footprint[2]; y <= pos[1] + footprint[3]; ++y )
	}

	{
		_cells[0]->setBlock(false);
	}
};
*/

#include "UnkSmartPtr.h"



class C1
{
	int length;
	char *str;
public:
	C1()
	{
		str = new char[512];
		strcpy(str, "abracadabra");
		length = strlen(str);
		std::cout << "C1" << std::endl;
	}
	C1( const char *c )
	{
		str = new char[ strlen(c) + 1 ];
		strcpy( str, c );
		length = strlen(str);

		std::cout << "C1" << std::endl;
	}
	C1( const C1& other )
	{
		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);
		length = strlen(str);
		std::cout << "C1 copy" << std::endl;
	}
	C1( C1&& other )
	{
		str = other.str;
		other.str = nullptr;
		length = other.length;
		std::cout << "C1 move" << std::endl;
	}
	~C1()
	{
		delete[] str;
		std::cout << "~C1" << std::endl;
	}


	C1& operator=( const C1& other)
	{
		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);
		length = strlen(str);
		std::cout << "C1 copy" << std::endl;
	}
	C1& operator=(C1&& other)
	{
		str = other.str;
		other.str = nullptr;
		length = other.length;
		std::cout << "C1 move" << std::endl;
	}
};


C1 MakeMeAStringPls( bool bb = true )
{
	if (bb)
	{
		C1 toret1("dkfjhngs jkhdbcjxkhvxkdfvb");
		return toret1;
	}
	C1 toret("azsdkfjlksdj gf ljkdsfg");
	return toret;
}


int main()
{

	//IInputRecieverPtr p(new Game());
	C1 b = C1();
	C1 d = C1();
	b = d;
	b = MakeMeAStringPls();



	Game game;
	game.init();
	while (game.app->isOpen()) {
		game.update(game.clock.restart().asSeconds());
	}
	return 0;
}


