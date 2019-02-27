#pragma once
#include "Game.h"
#include "Entity.h"
namespace SoloStudios {


	class GameObject : public Entity
	{
	public:

		/*GameObject();*/
		

		/*virtual void setTexture(Texture);
		virtual Sprite & GetSprite() { return _sprite; }*/

		void                setVelocity(sf::Vector2f velocity);
		sf::Vector2f        getVelocity() const;

		bool isVisible = false;
		

		
		virtual void Start(/*CManager *pManager,*/ rapidxml::xml_node<>* pNode);
		virtual void Update(sf::RenderWindow* pWindow);
		

	private:
		Vector2f		_velocity;
		Sprite			_sprite;
		Texture			_texture;
		Vector2f		_position;
		
		
		

	};
}
