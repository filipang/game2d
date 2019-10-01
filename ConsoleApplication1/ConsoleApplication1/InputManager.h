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

	std::set<IInputRecieverPtr> registeredList;
public:
	static InputManager* getInstance();

	void handleInput();

	void registerObj(IUnknownPtr obj) override;

	void unregisterObj(IUnknownPtr obj) override;

	InputManager();
};

