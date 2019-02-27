#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

namespace SoloStudios {
	class InputManager {

		public:

			InputManager() {}
			~InputManager(){}

			bool IsSpriteClick(Sprite object,  Mouse::Button button, RenderWindow &window);

			Vector2i GetMousePosition(RenderWindow &window);
		
	};
}
#endif