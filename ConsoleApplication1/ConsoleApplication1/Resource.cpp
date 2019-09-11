#include <vector>
#include "Resource.h"
#pragma once


void SinkContainer<class sink>::AddSink(class sink* a) 
{ 
	_sinks.push_back(a); 
}

void  SinkContainer<class sink>::RemoveSink(class sink* a)
{
	auto it = std::find(_sinks.begin(), _sinks.end(), a);
	if (it != _sinks.end())
		_sinks.erase(it);
}


void Resource::RegisterSink(IResourceSink *o) 
{ 
	AddSink(o); 
}

void Resource::UnregisterSink(IResourceSink *o) 
{ 
	RemoveSink(o); 
}


// from IRefCounted
void Resource::AddRef() 
{ 
		ref++; 
}

void Resource::Release() 
{
	ref--;
	if (ref == 0)
		for (auto* sink : _sinks)
			sink->OnDestroy(this);
	delete this;
}




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
}

