#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "moony/Sprite.h"

class Animation
{
public:
	std::string atlas;
	moony::Texture animation;

	sf::IntRect uvRect;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	std::map<std::string, int>  frame_count_map;
	std::map<std::string, int>	state_y_map;

	std::string state;

	float switchTime;
	float totalTime;

	float clip_count;
	float max_frame_count;

public:

	void update(float deltaTime);

	void setState(std::string state);

	void loadAnimation(std::string animation);

	Animation();

	~Animation();


};

