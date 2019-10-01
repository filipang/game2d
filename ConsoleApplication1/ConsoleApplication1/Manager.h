#pragma once
#include "Interfaces.h"

class Manager
{
public:
	static Manager* instance;

	std::set<IRegisterUnk*> registeredMgrList;
	std::set<IUnknownPtr> registeredObjList;
public:
	static Manager* getInstance();

public:
	void registerManager(IRegisterUnk* obj);
	void unregisterManager(IRegisterUnk *obj);
	void registerObj(IUnknown* obj);
	void unregisterObj(IUnknown* obj);
};
