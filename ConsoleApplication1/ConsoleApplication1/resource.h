#pragma once
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
	void AddSink(sink* a);
	void RemoveSink(sink* a);
};

class Resource : SinkContainer<IResourceSink>, IRefCounted
{
	int ref = 0;
public:
	void RegisterSink(IResourceSink *o);
	void UnregisterSink(IResourceSink *o);
	// from IRefCounted
	virtual void AddRef() override;
	virtual void Release() override;
};



class ResourceMgr : public IResourceSink
{
	std::vector<Resource*> _atlasses;

public:
	virtual void OnDestroy(Resource* r) override
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

