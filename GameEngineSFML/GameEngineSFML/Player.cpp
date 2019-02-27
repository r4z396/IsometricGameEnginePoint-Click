#include "Player.h"

namespace SoloStudios {


	Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switcTime) {
		_playerRectangle.setSize(sf::Vector2f(36,48));
		
		animator = new Animator(texture,imageCount,switcTime);
		direction = Directions::Stop;
		//lastDiretion = Directions::Down;

		/*_playerRectangle.setTexture(spriteSheetIdle);*/
	}

	void Player::Update(int row, float deltaTime) {
		
		
		animator->Update(row, deltaTime);
		_playerRectangle.setTextureRect(animator->uvRect);
	}
	void Player::changeSpriteSheet() {
		switch (direction)
		{
		
		case Directions::Stop:
			animator->changeSpriteSheet(spriteSheetIdle, sf::Vector2u(11, 1), 0.3f);
			_playerRectangle.setTexture(spriteSheetIdle);
			break;
		case Directions::Walking:
			animator->changeSpriteSheet(spriteSheetWalk, sf::Vector2u(13, 1), 0.1f);
			_playerRectangle.setTexture(spriteSheetWalk);
			break;
		}
	}

	void Player::moving() {
		direction = Directions::Walking;
		changeSpriteSheet();
	}

	void Player::stop()
	{
		direction = Directions::Stop;
		changeSpriteSheet();
	}

	void Player::HandleInput(sf::Event& event) {
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::A)
			{
				direction = Directions::Stop;
				changeSpriteSheet();
			}

			if (event.key.code == sf::Keyboard::B)
			{
				direction = Directions::Walking;
				changeSpriteSheet();
			}
		}
	}

}