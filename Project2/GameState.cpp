#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Titans {
	GameState::GameState(GameDataRef data) : _data(data) {

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 1", DINO_WALK_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 2", DINO_WALK_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 3", DINO_WALK_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 4", DINO_WALK_FRAME_4_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 5", DINO_WALK_FRAME_5_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 6", DINO_WALK_FRAME_6_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 7", DINO_WALK_FRAME_7_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 8", DINO_WALK_FRAME_8_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 9", DINO_WALK_FRAME_9_FILEPATH);
		_data->assets.LoadTexture("Dino Walk Frame 10", DINO_WALK_FRAME_10_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"), true);

		dino = new Dino(_data);

	}

	void GameState::HandleInput() {
		sf::Event event;
		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}

	void GameState::Update(float dt) {
		dino->Animate(dt);
	}

	void GameState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(_background);
		dino->Draw();
		_data->window.display();
	}
}
