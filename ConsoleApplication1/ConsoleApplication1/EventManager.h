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

	std::set<IEventRecieverPtr> registeredList;
public:
	static EventManager* getInstance();

	void registerObj(IUnknownPtr obj);

	void unregisterObj(IUnknownPtr obj) override;

	void handleEvent(sf::RenderWindow* app);

	EventManager();
};

