#pragma once

#include "Manager.h"

class CLevel : public CEntity
{
		int				m_nWidth;
		int				m_nHeight;
		char*			m_pLevel;
		CManager*	m_pManager;

	public:
		CLevel();
		~CLevel();

		void Start(CManager *pManager,rapidxml::xml_node<>* pNode);
		void Update(sf::RenderWindow* pWindow);
};
