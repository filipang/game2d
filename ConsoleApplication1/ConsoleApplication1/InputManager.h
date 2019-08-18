#pragma once
#include <SFML/Graphics.hpp>
class InputManager
{
public:
	static InputManager* instance;
	void handleKeyEvent(int keyCode);
public:
	static InputManager* getInstance();

	InputManager();
};

