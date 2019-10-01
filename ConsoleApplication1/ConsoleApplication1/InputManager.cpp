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

void InputManager::registerObj(IUnknownPtr obj)
{
	IInputRecieverPtr toAdd = nullptr;
	if (obj->QueryInterface(IInputReciever::myType, (void**)&toAdd) == false)
		return;

	//toAdd->AddRef();
	registeredList.insert(toAdd);
}

void InputManager::unregisterObj(IUnknownPtr obj)
{
	IInputRecieverPtr toRem = nullptr;
	if (obj->QueryInterface(IInputReciever::myType, (void**)&toRem) == false)
		return;

	registeredList.erase(toRem);
	//toRem->Release();
}

void InputManager::handleInput() {
	for (IInputRecieverPtr obj : registeredList) {
		obj->handleInput();
	}
}

InputManager::InputManager() {
	
}

