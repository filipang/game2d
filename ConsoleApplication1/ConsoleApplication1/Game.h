#pragma once

class Game : InputRegistrable
{
public:

	sf::RenderWindow* app;
	sf::View* view;
	moony::SpriteBatch* batch;

	class Player* player;
	sf::Clock clock;
	float deltaTime;



public:
	Game();
	~Game();

	void handleInput();
	void init();
	void update(float deltaTime);
};

