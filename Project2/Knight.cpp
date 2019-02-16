#include "Knight.hpp"


namespace Titans {
	Knight::Knight( GameDataRef data ) : _data (data){

		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 9"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Run Frame 10"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 9"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Attack Frame 10"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 4"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 5"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 6"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 7"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 8"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 9"));
		_animationFrames.push_back(_data->assets.GetTexture("Knight Dead Frame 10"));

		_knightSprite.setTexture( _animationFrames.at(_animationIterator) );
	}

	void Knight::Draw() {
		_data->window.draw(_knightSprite);
	}

	void Knight::runAnimate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > KNIGHT_RUN_ANIMATION_DURATION/ _animationFrames.size()) {
			_animationIterator = (_animationIterator + 1) % _animationFrames.size();
			_knightSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
		_knightSprite.move(KNIGHT_RUN_SPEED * dt, 0);
	}
	void Knight::attackAnimate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > KNIGHT_ATTACK_ANIMATION_DURATION/ _animationFrames.size()) {
			_animationIterator = (_animationIterator + 1) % _animationFrames.size();
			_knightSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
		_knightSprite.move(KNIGHT_ATTACK_SPEED * dt, 0);
	}
	void Knight::deadAnimate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > KNIGHT_DEAD_ANIMATION_DURATION/ _animationFrames.size()) {
			_animationIterator = (_animationIterator + 1) % _animationFrames.size();
			_knightSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
		_knightSprite.move(KNIGHT_DEAD_SPEED * dt, 0);
	}
}
