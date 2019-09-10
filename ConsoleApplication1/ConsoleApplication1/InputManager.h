#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <set>
#include "InputRegistrable.h"

class InputManager
{
public:
	static InputManager* instance;

	std::set<InputRegistrable*> registeredList;
public:
	static InputManager* getInstance();

	void handleInput();

	void registerObj(InputRegistrable* obj);

	void unregisterObj(InputRegistrable *obj);

	void handleEvent(sf::RenderWindow* app);

	InputManager();
};

