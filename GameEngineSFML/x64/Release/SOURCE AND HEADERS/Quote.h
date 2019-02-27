#pragma once
#include "Entity.h"
#include <string>
#include "SFML/Graphics.hpp"

namespace SoloStudios {
	class Quote :
		public Entity
	{
	public:
		Quote(sf::Font& font);

		~Quote();

		void Update(sf::RenderWindow* pWindow);


		//Info
		float _duration;
		sf::Vector2f pos;
		std::string text;
		sf::Text _text;
	private:
		


		

	};


}
