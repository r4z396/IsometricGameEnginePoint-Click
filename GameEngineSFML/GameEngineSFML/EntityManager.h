#pragma once
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <list>

#include <fstream>
#include "Entity.h"
#include "ExternalTools.h"
namespace SoloStudios {

	
	class EntityManager
	{
	public:

		EntityManager();
		~EntityManager();

		std::string			m_strAssets;
		std::list<Entity*>	m_Entities;

		Entity* GetAssetByID(int nID);

	};

}
#endif







