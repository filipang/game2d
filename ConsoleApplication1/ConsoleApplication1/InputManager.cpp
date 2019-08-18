#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include <iostream>

InputManager* InputManager::instance = 0;

InputManager* InputManager::getInstance()
{
	if (InputManager::instance == 0) {
		InputManager::instance = new InputManager();
	}
	return InputManager::instance;
}

void InputManager::handleKeyEvent(int keyCode) {
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
}

InputManager::InputManager() {
	
}

