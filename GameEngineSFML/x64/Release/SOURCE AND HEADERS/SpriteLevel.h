#pragma once
#ifndef SPRITE_LEVEL_H
#define SPRITE_LEVEL_H
#include "ExternalTools.h"
#include "Entity.h"
#include "EntityManager.h"


namespace SoloStudios {
	class SpriteLevel: public Entity
	{
	public:
		

		/*Node(Vector2i position);

		bool isWalkable = false;*/

		sf::Texture			m_Texture;
		sf::Sprite			m_Sprite;
		sf::Vector2f		m_vPos;
		SpriteLevel*					m_pNode;

	
		SpriteLevel();
		SpriteLevel(SpriteLevel* pImage);

		void SetPosition(sf::Vector2f pos);

		virtual void Start(EntityManager *pManager, rapidxml::xml_node<>* pNode);
		virtual void Update(sf::RenderWindow* pWindow);
		
	};

}

#endif