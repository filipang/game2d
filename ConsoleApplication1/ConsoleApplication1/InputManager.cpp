#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include <iostream>
#include "Entity.h"

InputManager* InputManager::instance = 0;

InputManager* InputManager::getInstance()
{
	if (InputManager::instance == 0) {
		InputManager::instance = new InputManager();
	}
	return InputManager::instance;
}

void InputManager::handleInput(Entity* player) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//player->move
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

	}
}

void InputManager::handleEvent(sf::Event event, Entity* player) {
	
	switch (event.type) {
	case event.KeyPressed:
		std::cout << typeid(event.key.code).name() << std::endl;
		player->sprite->move(20.0f, 0.0f);

	default:
		break;
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

InputManager::InputManager() {
	
}

