#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class InputManager
{
public:
	static InputManager* instance;
public:
	static InputManager* getInstance();

	void handleInput(Entity* player);

	void handleEvent(sf::Event event, Entity* player);

	InputManager();
};

