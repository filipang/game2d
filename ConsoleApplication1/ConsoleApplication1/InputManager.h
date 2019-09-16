#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <set>
#include "IUnknown.h"
#include "Interfaces.h"

class InputManager : public IRegisterUnk
{
public:
	static InputManager* instance;

	std::set<IInputReciever*> registeredList;
public:
	static InputManager* getInstance();

	void handleInput();

	void registerObj(IUnknown* obj);

	void unregisterObj(IUnknown *obj);

	InputManager();
};

