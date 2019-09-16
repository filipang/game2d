#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <set>
#include "IUnknown.h"
#include "Interfaces.h"

class EventManager : public IRegisterUnk
{
public:
	static EventManager* instance;

	std::set<IEventReciever*> registeredList;
public:
	static EventManager* getInstance();

	void registerObj(IUnknown* obj);

	void unregisterObj(IUnknown *obj);

	void handleEvent(sf::RenderWindow* app);

	EventManager();
};

