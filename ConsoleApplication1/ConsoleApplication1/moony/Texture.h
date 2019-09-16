#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>
#include <unordered_map>
#include "../IUnknown.h"
#include "../Interfaces.h"
#include <SFML/Graphics.hpp>


namespace moony
{
	// The Texture class is similar to the SFML sf::Texture class but was designed to work specifically with the TextureAtlas class.
	struct Texture : CoUnknown1<ITexture>
	{
		Texture(const sf::Texture* texture = NULL, sf::IntRect rect = sf::IntRect());

		const sf::Texture* m_texture;
		sf::IntRect m_rect;
	};
}


#endif