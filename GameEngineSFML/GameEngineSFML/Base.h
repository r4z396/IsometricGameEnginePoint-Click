#pragma once

#include <iostream>
#include <list>
#include <fstream>
#include "rapidxml.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class CManager;

rapidxml::xml_node<>* FindChildNode(rapidxml::xml_node<>* pNode,const char* szName);
rapidxml::xml_attribute<>* FindAttribute(rapidxml::xml_node<>* pNode,const char* szName);

// ----------------------------------------------------------------------------

class CEntity
{
	protected:
		int							m_nID;

	public:
		CEntity();

		virtual void Start(CManager *pManager,rapidxml::xml_node<>* pNode);
		virtual void Update(sf::RenderWindow* pWindow);

		friend class CManager;
};

// ----------------------------------------------------------------------------

class CImage : public CEntity
{
		sf::Texture			m_Texture;
		sf::Sprite			m_Sprite;
		sf::Vector2f		m_vPos;
		CImage*					m_pImage;

	public:
		CImage();
		CImage(CImage* pImage); 

		void SetPosition(sf::Vector2f pos);

		virtual void Start(CManager *pManager,rapidxml::xml_node<>* pNode);
		virtual void Update(sf::RenderWindow* pWindow);
};

