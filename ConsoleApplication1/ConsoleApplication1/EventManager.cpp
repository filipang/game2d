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

void EventManager::registerObj(IUnknown *obj)
{
	IEventReciever *toAdd = nullptr;
	if (obj->QueryInterface(IEventReciever::myType, (void**)&toAdd) == false)
		return;

	toAdd->AddRef();
	registeredList.insert(toAdd);
}

void EventManager::unregisterObj(IUnknown *obj)
{
	IEventReciever *toRem = nullptr;
	if (obj->QueryInterface(IEventReciever::myType, (void**)&toRem) == false)
		return;

	registeredList.erase(toRem);
	toRem->Release();
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

		for (IEventReciever* obj : registeredList) {
			obj->handleEvent(event);
		}

		/*
		switch (event.type) {
		case event.KeyPressed:
			std::cout << typeid(event.key.code).name() << std::endl;
			break;
		case event.Closed:
			app->close();
			break;
		default:
			break;
		}*/
	}
	/*switch (keyCode)
	{
		// Process the up, down, left and right keys
	case sf::Keyboard::Up:
		//upFlag = true; break;
	case sf::Keyboard::Down:
		//downFlag = true; break;
	case sf::Keyboard::Left:
		//leftFlag = true; break;
	case sf::Keyboard::Right:
		//rightFlag = true; break;
	default: break;
	}
	switch (keyCode) {
	case 22:
		printf("Pressed W\n");
		break;
	case 0:
		printf("Pressed A\n");
		break;
	case 18:
		printf("Pressed S\n");
		break;
	case 3:
		printf("Pressed D\n");
		break;
	case 4:
		printf("Pressed E\n");
		break;
	case 57:
		printf("Pressed Space\n");
		break;
	}
	*/
}

EventManager::EventManager() {

}

