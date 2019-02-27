#pragma once

#include "Animator.h"
namespace SoloStudios {


	class Player {

		
		
		Animator* animator;
		enum Directions { Up, Down, Left, Right, Stop,Walking };

		//SpriteSheets
		
		
		float player_Speed;
		Directions  direction;  ///<Direccion actual de jugador
		//Directions lastDiretion; ///<Ultima direccion del jugador
	public:
		void moving();
		void stop();
		Player(sf::Texture *texture, sf::Vector2u imageCount, float switcTime);
		sf::RectangleShape _playerRectangle;
		sf::Texture* spriteSheetIdle;
		sf::Texture* spriteSheetWalk;
		void Update(int row, float deltaTime);
		void HandleInput(sf::Event& event);
		void MovePlayer();

		void changeSpriteSheet();
	};
}
