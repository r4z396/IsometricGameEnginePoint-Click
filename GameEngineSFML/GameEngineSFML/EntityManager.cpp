#include "EntityManager.h"


namespace SoloStudios {

	/////////////////////////////////////////////////////////////////////////////////////////7
	//
	/////////////////////////////////////////////////////////////////////////////////////////////
	EntityManager::EntityManager()
	{
	}


	EntityManager::~EntityManager()
	{
	}

	Entity* EntityManager::GetAssetByID(int nID)
	{
		std::list<Entity*>::iterator i;

		for (i = m_Entities.begin(); i != m_Entities.end(); ++i) {
			if ((*i)->m_nID == nID) return (*i);
		}
		return NULL;
	}


}