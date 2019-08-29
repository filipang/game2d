// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"
#include "Entity.h"

int main()
{
	sf::RenderWindow app(sf::VideoMode(1500, 900), "SFML STARTUP", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1500.0f, 900.0f));
	ResourceManager::getInstance()->loadAtlas("moony_texture_packer_ready");
	moony::SpriteBatch batch;


	Entity player(200.0f, 200.0f, "man.png", "walk", 220.0f);

	sf::Clock clock;
	float deltaTime = 0.0f;
	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == event.Closed) { app.close(); }
			else { InputManager::getInstance()->handleEvent(event, &player); }
			
		}
		InputManager::getInstance()->handleInput(player);

		deltaTime = clock.restart().asSeconds();
		player.update(deltaTime);
		app.clear(sf::Color(255,255,255,255));
		batch.clear();
		batch.draw(*player->sprite);
		app.setView(view);
		app.draw(batch);
		app.display();
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file