
#include "SpriteLevel.h"
#include <string>

namespace SoloStudios {


	SpriteLevel::SpriteLevel()
	{
		m_nID = 0;
		m_pNode = NULL;
	}

	SpriteLevel::SpriteLevel(SpriteLevel* pImage)
	{
		m_pNode = pImage;
	}

	void SpriteLevel::SetPosition(sf::Vector2f pos)
	{
		m_vPos = pos;
	}

	void SpriteLevel::Start(EntityManager *pManager, rapidxml::xml_node<>* pNode)
	{

		rapidxml::xml_attribute<>*	pAttr = FindAttribute(pNode, "id");
		if (pAttr != NULL) m_nID = atoi(pAttr->value());

		pAttr = FindAttribute(pNode, "x");
		if (pAttr != NULL) m_vPos.x = atof(pAttr->value());
		pAttr = FindAttribute(pNode, "y");
		if (pAttr != NULL) m_vPos.y = atof(pAttr->value());

		std::string  file = pManager->m_strAssets + pNode->value();
		if (m_Texture.loadFromFile(file)) {

			m_Sprite.setTexture(m_Texture);

		}

	}

	void SpriteLevel::Update(sf::RenderWindow* pWindow)
	{
		m_Sprite.setPosition(m_vPos);
		//m_Sprite.setRotation(45.f);
		m_Sprite.setScale(sf::Vector2f(2.f, 2.f));
		pWindow->draw(m_Sprite);
	}

	
}

