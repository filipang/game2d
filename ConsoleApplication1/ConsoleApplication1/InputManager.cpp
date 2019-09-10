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

void InputManager::handleInput() {
	for (InputRegistrable* obj : registeredList) {
		obj->handleInput();
	}
}

void InputManager::registerObj(InputRegistrable *obj)
{
	registeredList.insert(obj);
}

void InputManager::unregisterObj(InputRegistrable *obj)
{
	registeredList.erase(obj);
}

void InputManager::handleEvent(sf::RenderWindow* app) {
	sf::Event event;
	while (app->pollEvent(event))
	{
		switch (event.type){
		case event.KeyPressed:
			std::cout << typeid(event.key.code).name() << std::endl;
			break;
		case event.Closed:
			app->close();
			break;
		default:
			break;
		}
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

