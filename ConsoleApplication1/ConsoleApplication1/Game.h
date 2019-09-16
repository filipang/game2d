#pragma once

class Game : public CoUnknown2<IInputReciever, IEventReciever>
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
	void handleEvent(sf::Event e);
	void init();
	void update(float deltaTime);
};

