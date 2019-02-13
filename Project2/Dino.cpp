#include "Dino.hpp"


namespace Titans {
	Dino::Dino( GameDataRef data ) : _data (data){

		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 9"));
		_animationFrames.push_back(_data->assets.GetTexture("Dino Walk Frame 10"));

		_dinoSprite.setTexture( _animationFrames.at(_animationIterator) );
	}

	void Dino::Draw() {
		_data->window.draw(_dinoSprite);
	}

	void Dino::walkAnimate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > DINO_WALK_ANIMATION_DURATION/ _animationFrames.size()) {
			_animationIterator = (_animationIterator + 1) % _animationFrames.size();
			_dinoSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
		_dinoSprite.move(DINO_WALK_SPEED * dt, 0);
	}
}

