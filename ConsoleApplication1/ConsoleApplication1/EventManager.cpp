#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include <iostream>
#include "Entity.h"

EventManager* EventManager::instance = 0;

EventManager* EventManager::getInstance()
{
	if (EventManager::instance == 0) {
		EventManager::instance = new EventManager();
	}
	return EventManager::instance;
}

void EventManager::registerObj(IUnknownPtr obj)
{
	IEventRecieverPtr toAdd = nullptr;
	if (obj->QueryInterface(IEventReciever::myType, (void**)&toAdd) == false)
		return;

	//toAdd->AddRef();
	registeredList.insert(toAdd);
}

void EventManager::unregisterObj(IUnknownPtr obj)
{
	IEventRecieverPtr toRem = nullptr;
	if (obj->QueryInterface(IEventReciever::myType, (void**)&toRem) == false)
		return;

	registeredList.erase(toRem);
	//toRem->Release();
}

/*
void EventManager::handleInput() {
	for (IInputReciever* obj : registeredList) {
		obj->handleInput();
	}
}*/

void EventManager::handleEvent(sf::RenderWindow* app) {
	sf::Event event;
	while (app->pollEvent(event))
	{

		for (IEventRecieverPtr obj : registeredList) {
			obj->handleEvent(event);
		}

	}
}

EventManager::EventManager() {

}

