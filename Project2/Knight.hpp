#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Titans {
	class Knight{

	public:
		Knight(GameDataRef data);
		
		void Draw();
		void runAnimate(float dt);
		void attackAnimate(float dt);
		void deadAnimate(float dt);
	private:
		GameDataRef _data;
		sf::Sprite _knightSprite;

		std::vector<sf::Texture> _animationFrames;
		unsigned int _animationIterator;

		sf::Clock _clock;
	};

}
