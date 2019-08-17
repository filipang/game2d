// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "moony/SpriteBatch.h"

int main()
{
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML STARTUP", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 600.0f));
	TextureManager::getInstance()->loadAtlas("moony_texture_packer_ready");
	moony::Sprite sprite = SpriteManager::getInstance()->getSpriteByName("bob.jpg");
	sprite.setOrigin(sprite.m_subtexture.m_rect.width / 2, sprite.m_subtexture.m_rect.height / 2);
	moony::SpriteBatch batch;
	view.move(200.0f, 200.0f);
	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == event.Closed) {
				app.close();
			}


		}
		app.clear();
		batch.clear();
		sprite.getPosition();
		batch.draw(sprite);
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
