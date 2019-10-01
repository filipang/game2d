#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "TextureManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "EventManager.h"
#include "EventManager.h"
#include "Manager.h"
#include "moony/SpriteBatch.h"
#include "Animation.h"
#include "Game.h"
#include "IUnknown.h"
#include "Player.h"

Game::Game()
{
}


Game::~Game()
{
}

void Game::handleInput()
{
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
		std::cout << "Before.. " <<player->GetRefCount() << std::endl;
		InputManager::getInstance()->registerObj(player);
		std::cout << "After.. " <<player->GetRefCount() << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
		std::cout << "Before.. " << player->GetRefCount() << std::endl;
		InputManager::getInstance()->unregisterObj(player);
		std::cout << "After.. " << player->GetRefCount() << std::endl;
	}
	*/
}

void Game::handleEvent(sf::Event e) {
	switch (e.type) {
	case sf::Event::KeyPressed:
		if (e.key.code == sf::Keyboard::Equal) {
			std::cout << "Before.. " << player->GetRefCount() << std::endl;
			InputManager::getInstance()->registerObj(player);
			std::cout << "After.. " << player->GetRefCount() << std::endl;
		}
		if (e.key.code == sf::Keyboard::Dash) {
			std::cout << "Before.. " << player->GetRefCount() << std::endl;
			InputManager::getInstance()->unregisterObj(player);
			std::cout << "After.. " << player->GetRefCount() << std::endl;
		}
		if (e.key.code == sf::Keyboard::V) {
			std::cout << "GAME OBJ HAS THIS MANY REFS: " << this->GetRefCount() << std::endl;
		}
		break;
	case sf::Event::Closed:
		app->close();
		break;
	default:
		break;
	}

}

void Game::init()
{
	app = new sf::RenderWindow(sf::VideoMode(1500, 900), "SFML STARTUP", sf::Style::Close | sf::Style::Resize);
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1500.0f, 900.0f));
	
	ResourceManager::getInstance()->loadAtlas("moony_texture_packer_ready");
	
	batch = new moony::SpriteBatch();
	player = new Player(200.0f, 200.0f, "man.png", "walk", 220.0f);

	Manager::getInstance()->registerManager(InputManager::getInstance());
	Manager::getInstance()->registerManager(EventManager::getInstance());
	Manager::getInstance()->registerManager(SpriteManager::getInstance());
	Manager::getInstance()->registerManager(TextureManager::getInstance());
	Manager::getInstance()->registerObj(player);
	Manager::getInstance()->registerObj(this);

}

void Game::update(float deltaTime)
{
	
	EventManager::getInstance()->handleEvent(app);
	InputManager::getInstance()->handleInput();

	player->update(deltaTime);
	app->clear(sf::Color(255, 255, 255, 255));
	batch->clear();
	batch->draw(*player->sprite);
	app->setView(*view);
	app->draw(*batch);
	app->display();
}
