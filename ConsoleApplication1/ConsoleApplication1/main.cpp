// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"

int main()
{
	sf::RenderWindow app(sf::VideoMode(1500, 900), "SFML STARTUP", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1500.0f, 900.0f));
	TextureManager::getInstance()->loadAtlas("moony_texture_packer_ready");
	moony::Sprite sprite2 = SpriteManager::getInstance()->getSpriteByName("man.png");
	sprite2.setOrigin(sprite2.m_subtexture.m_rect.width / 2, sprite2.m_subtexture.m_rect.height / 2);

	moony::SpriteBatch batch;

	
	Animation a;
	moony::Texture texture = TextureManager::getInstance()->getTextureByName("man.png");

	moony::Sprite sprite(texture);
	a.loadAnimation("man.png", &texture, &texture.m_rect, &sprite);
	a.setState("walk");
	//a.update();
	sf::Clock clock;
	float deltaTime = 0.0f;
	while (app.isOpen())
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			switch (event.type) {
			case event.Closed:
				app.close();
				break;
			case event.KeyPressed:
				InputManager::getInstance()->handleKeyEvent(event.key.code);
				break;

			}

		}
		
		deltaTime = clock.restart().asSeconds();
		a.switchTime = 0.00025f;
		a.update(clock.getElapsedTime().asSeconds());
		app.clear();
		batch.clear();
		
		sprite.m_subtexture = texture;
		batch.draw(sprite);
		//batch.draw(sprite2);
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
