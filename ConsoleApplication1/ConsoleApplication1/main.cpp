// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int main()
{


	auto *a = createResource();

	a->Release();

	Game game;
	game.init();
	while (game.app->isOpen()) {
		game.update(game.clock.restart().asSeconds());
	}
	return 0;
}


