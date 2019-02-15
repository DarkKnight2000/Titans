#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Dino.hpp"
#include "Knight.hpp"
namespace Titans {
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
		Knight *knight;
		Dino *dino;
	};

}

