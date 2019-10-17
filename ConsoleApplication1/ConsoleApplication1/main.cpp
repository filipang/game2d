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

#include "moony/Sprite.h"

#include "DuktapeRunner.h"

duk_ret_t __n_add_numbers(duk_context *ctx)
{
	int nr1 = duk_require_int(ctx, 0);
	int nr2 = duk_require_int(ctx, 1);
	int nr = nr1 + nr2;
	duk_push_number(ctx, nr);
	return 1;
}

void duk_run_me_script()
{
	DuktapeRunner dk;

	duk_push_c_function(dk._ctx, __n_add_numbers, 2);
	duk_put_prop_string(dk._ctx, -2, "addNrs");

	dk.push_file_as_string_and_eval ( "testadd.js" );
	dk.run_duktape ( "testme" );
}

#include "nav/CNavSample.h"

int main()
{
	CNavSample a;
	a.run();
	return 0;


	duk_run_me_script();

	Game game;
	game.init();
	while (game.app->isOpen()) {
		game.update(game.clock.restart().asSeconds());
	}
	return 0;
}