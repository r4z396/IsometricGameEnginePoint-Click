#pragma once

#include "Base.h"

class CManager
{
	public:
		std::string					m_strAssets;
		std::list<CEntity*>	m_Entities;

	public:
		CManager();

		CEntity* GetAssetByID(int nID);
};
