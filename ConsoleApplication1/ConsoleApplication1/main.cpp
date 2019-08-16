// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"

int main()
{
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML STARTUP", sf::Style::Close | sf::Style::Titlebar);
	TextureManager::getInstance()->loadAtlas("moony_texture_packer_ready");// = SpriteManager::getInstance()->getSpriteByName("soup");
	sf::Sprite sprite = SpriteManager::getInstance()->getSpriteByName("bob.jpg");
	std::cout << "Aye " << sprite.getGlobalBounds().width;
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
		app.draw(sprite);
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
