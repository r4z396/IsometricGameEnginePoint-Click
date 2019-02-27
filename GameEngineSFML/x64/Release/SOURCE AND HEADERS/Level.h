#pragma once
//#include "Node.h"
#include "rapidxml.hpp"
#include "EntityManager.h"
#include "SpriteLevel.h"
#include "Node.h"
#include "DialogManager.h"
namespace SoloStudios {

	

	class Level: public Entity
	{
	public:
		int				m_nWidth;
		int				m_nHeight;		
		char* dataLevel;

		Node* start=NULL;
		Node* goal=NULL;
		Node** nodeGrid=NULL;
	
		EntityManager entityManager;
		DialogManager* dialogManager;

		bool firstLoopLevelInit=true;
		bool canDraw;
		sf::Vector2f startPositionPlayer;
		
		Level();
		~Level();

		void hideDebugNodes();
		
		void deleteLevel();

		sf::Vector2f Init(/*EntityManager *pManager,*/rapidxml::xml_node<>* pNode);

		void initNodeGrid();

		void initDialogsSystem(sf::Font& font);

		void Update(sf::RenderWindow* pWindow);

	
		
	};

}

