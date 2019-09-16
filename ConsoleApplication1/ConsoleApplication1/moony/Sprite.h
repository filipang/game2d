#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

#include "Texture.h"

namespace moony
{
	struct Sprite : public sf::Transformable, public CoUnknown1<ISprite>
	{
		Sprite();
		Sprite(const Texture& subtexture, int layer = 0, sf::Color color = sf::Color::White);

		Texture m_subtexture;
		sf::Color m_color;
		int m_layer;

	};
}

#endif