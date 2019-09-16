#pragma once
#include "Interfaces.h"

class Manager : public IRegisterUnk
{
public:
	static Manager* instance;

	std::set<IRegisterUnk*> registeredMgrList;
	std::set<void*> registeredObjList;
public:
	static Manager* getInstance();

public:
	void registerManager(IRegisterUnk* obj);
	void unregisterManager(IRegisterUnk *obj);
	virtual void registerObj(IUnknown* obj) override;
	virtual void unregisterObj(IUnknown *obj) override;
};
