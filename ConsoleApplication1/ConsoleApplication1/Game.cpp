#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"
#include "Game.h"
#include "Player.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
		InputManager::getInstance()->registerObj(player);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
		InputManager::getInstance()->unregisterObj(player);
	}
}

void Game::init()
{
	app = new sf::RenderWindow(sf::VideoMode(1500, 900), "SFML STARTUP", sf::Style::Close | sf::Style::Resize);
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1500.0f, 900.0f));
	
	ResourceManager::getInstance()->loadAtlas("moony_texture_packer_ready");
	
	batch = new moony::SpriteBatch();
	player = new Player(200.0f, 200.0f, "man.png", "walk", 220.0f);
	InputManager::getInstance()->registerObj(player);
	InputManager::getInstance()->registerObj(this);

}

void Game::update(float deltaTime)
{
	
	InputManager::getInstance()->handleEvent(app);
	InputManager::getInstance()->handleInput();

	player->update(deltaTime);
	app->clear(sf::Color(255, 255, 255, 255));
	batch->clear();
	batch->draw(*player->sprite);
	app->setView(*view);
	app->draw(*batch);
	app->display();
}
