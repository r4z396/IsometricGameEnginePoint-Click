#include "Animator.h"
#include <iostream>

namespace SoloStudios {
	Animator::Animator(sf::Texture *texture, sf::Vector2u imageCount, float switcTime)
	{
		_imageCount = imageCount;
		
		_switchTime = switcTime;
		_totalTime = 0;
		_currentImage.x = 0;
		uvRect.width = texture->getSize().x/float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
	}

	void Animator::changeSpriteSheet(sf::Texture *texture, sf::Vector2u imageCount, float switcTime)
	{
		_imageCount = imageCount;

		_switchTime = switcTime;
		_totalTime = 0;
		_currentImage.x = 0;
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
	}

	Animator::~Animator()
	{
	}

	void Animator::Update(int row, float deltaTime) {
		_currentImage.y = row;
		_totalTime += deltaTime;

		if (_totalTime >= _switchTime) {
			_totalTime -= _switchTime;
			_currentImage.x++;
			if (_currentImage.x >= _imageCount.x) {
				_currentImage.x = 0;
			}
		}
		uvRect.left = _currentImage.x*uvRect.width;
		uvRect.top = _currentImage.y*uvRect.height;
		
		//std::cout << _currentImage.x << "CURRENT IMAGE LEFT";
	}

}
