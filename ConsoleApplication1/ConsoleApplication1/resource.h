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
public:
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
	virtual void OnDestroy(Resource* r) override;
	void AddResource(Resource* a);
};


