#include "Knight.hpp"


namespace Titans {
	Knight::Knight( GameDataRef data ) : _data (data){

		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 9"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Walk Frame 10"));

		_knightSprite.setTexture( _animationFrames.at(_animationIterator) );
	}

	void Knight::Draw() {
		_data->window.draw(_knightSprite);
	}

	void Knight::walkAnimate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > KNIGHT_WALK_ANIMATION_DURATION/ _animationFrames.size()) {
			_animationIterator = (_animationIterator + 1) % _animationFrames.size();
			_knightSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
		_knightSprite.move(KNIGHT_WALK_SPEED * dt, 0);
	}
}
