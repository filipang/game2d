#pragma once
#include "UnkSmartPtr.h"

#define PURE = 0

const int IID_IUnknown = 0;

class IUnknown
{
public:
	static const int myType = IID_IUnknown;
public:
	virtual bool QueryInterface(int type, void** ppv) PURE;
	virtual int AddRef() PURE;
	virtual int Release() PURE;
	virtual int GetRefCount() PURE;
};
typedef UnkSmartPtr<IUnknown> IUnknownPtr;

class IRegisterUnk
{
public:
	virtual void registerObj(IUnknownPtr obj) PURE;
	virtual void unregisterObj(IUnknownPtr obj) PURE;
};

#define ADDREFRELEASE			private:									\
									int refCount = 0;						\
																			\
								public:										\
									virtual int AddRef() override			\
									{										\
										return ++refCount;					\
									}										\
									virtual int Release() override			\
									{										\
										int cRef = --refCount;				\
										if (cRef == 0)						\
											delete this;					\
										return cRef;						\
									}										\
									virtual int GetRefCount() override		\
									{										\
										return refCount;					\
									}

template<class I1>
class CoUnknown1 : public virtual I1
{
	ADDREFRELEASE
public:
	virtual ~CoUnknown1() {}

public:
	virtual bool QueryInterface(int type, void** ppv) override
	{
		*ppv = nullptr;
		if (type == I1::myType)
			*ppv = (void*)(static_cast<I1*>(this));

		if (*ppv) { AddRef(); return true; }
		return false;
	}

};
template<class I1, class I2>
class CoUnknown2 : public I1, public I2
{
	ADDREFRELEASE
public:
	virtual ~CoUnknown2() {}

public:
	virtual bool QueryInterface(int type, void** ppv) override
	{
		*ppv = nullptr;
		if (type == I1::myType)
		{
			*ppv = (void*)(static_cast<I1*>(this));
		}
		if (type == I2::myType)
		{
			*ppv = (void*)(static_cast<I2*>(this));
		}
		if (*ppv) { AddRef(); return true; }
		return false;
	}
};

template<class I1, class I2, class I3>
class CoUnknown3 : public I1, public I2, public I3
{
	ADDREFRELEASE
public:
	virtual ~CoUnknown3() {}

public:
	virtual bool QueryInterface(int type, void** ppv) override
	{
		*ppv = nullptr;
		if (type == I1::myType)
		{
			*ppv = (void*)(static_cast<I1*>(this));
		}
		if (type == I2::myType)
		{
			*ppv = (void*)(static_cast<I2*>(this));
		}
		if (type == I3::myType)
		{
			*ppv = (void*)(static_cast<I3*>(this));
		}
		if (*ppv) { AddRef(); return true; }
		return false;
	}
};