#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class InputManager
{
public:
	static InputManager* instance;
	void handleEvent(sf::Event event, Entity player);
public:
	static InputManager* getInstance();

	InputManager();
};

