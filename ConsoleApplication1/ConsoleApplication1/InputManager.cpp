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
	case 0: 
		printf("Pressed A\n");
		break;
	case 22:
		printf("Pressed W");
	}
	printf("event handled\n Key Code %d\n", keyCode);


}

InputManager::InputManager() {
	
}

