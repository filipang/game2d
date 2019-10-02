// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"
#include "Entity.h"
#include "Game.h"
#include "UnkSmartPtr.h"


int main()
{
	Game game;
	game.init();
	while (game.app->isOpen()) {
		game.update(game.clock.restart().asSeconds());
	}
	return 0;
}


