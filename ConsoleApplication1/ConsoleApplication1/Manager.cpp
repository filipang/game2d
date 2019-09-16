#include <set>
#include "Manager.h"


Manager* Manager::instance = nullptr;

Manager* Manager::getInstance()
{
	if (Manager::instance == 0) {
		Manager::instance = new Manager();
	}
	return Manager::instance;
}

void Manager::registerManager(IRegisterUnk* obj)
{
	registeredMgrList.insert(obj);
}
void Manager::unregisterManager(IRegisterUnk *obj)
{
	registeredMgrList.erase(obj);
}
void Manager::registerObj(IUnknown *obj)
{
	obj->AddRef();
	registeredObjList.insert(obj);
	for (auto mgr : registeredMgrList)
		mgr->registerObj(obj);
}

void Manager::unregisterObj(IUnknown *obj)
{
	registeredObjList.erase(obj);
	obj->Release();
	for (auto mgr : registeredMgrList)
		mgr->unregisterObj(obj);
}