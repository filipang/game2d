#pragma once
#include <vector>
#include "Resource.h"

template<class sink>
void SinkContainer<sink>::AddSink(sink* a) 
{ 
	_sinks.push_back(a); 
}

template<class sink>
void SinkContainer<sink>::RemoveSink(sink* a)
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

void ResourceMgr::OnDestroy(class Resource* r)
{
	auto it = std::find(_atlasses.begin(), _atlasses.end(), r);
	if (it != _atlasses.end())
		_atlasses.erase(it);
}

void ResourceMgr::AddResource(Resource* a)
{
	_atlasses.push_back(a);
	a->RegisterSink(this);
}

/*
ResourceMgr rmg;
Resource* createResource()
{
	auto *a = new Resource();
	rmg.AddResource(a);
	return a;
}
*/

