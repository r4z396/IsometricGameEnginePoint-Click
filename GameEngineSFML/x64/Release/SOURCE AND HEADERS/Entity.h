#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <list>
#include <fstream>
#include "rapidxml.hpp"
#include <SFML/Graphics.hpp>

namespace SoloStudios {

	class EntityManager;

	class Entity
	{
	public:
		Entity();
	

	protected:
		int					m_nID;
		

	public:
		

		virtual void Start(EntityManager *pManager, rapidxml::xml_node<>* pNode);
		virtual void Update(sf::RenderWindow* pWindow);

		friend class EntityManager;
		
	};



}
#endif
