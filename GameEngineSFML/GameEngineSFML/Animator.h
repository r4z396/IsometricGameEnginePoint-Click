#pragma once
#ifndef ANIMATOR_H
#define ANIMATOR_H
#include "SFML/Graphics.hpp"
namespace SoloStudios {
	class Animator
	{
	public:
		Animator(sf::Texture *texture, sf::Vector2u imageCount, float switcTime);
		//This fucntions is for changing the the spritesheet when you have different spritesheets of different lenght maybe you use it
		void changeSpriteSheet(sf::Texture *texture, sf::Vector2u imageCount, float switcTime);
		~Animator();

		void Update(int row, float deltaTime);
		//uv rect for the texture
		sf::IntRect uvRect;

	private:
		sf::Vector2u _imageCount;
		sf::Vector2u _currentImage;

		float _totalTime;
		float _switchTime;
	};

}

#endif

