#include "Manager.h"


using namespace std;
using namespace sf;
using namespace rapidxml;

// ---------------------------------------------------------------

CManager::CManager()
{
}

CEntity* CManager::GetAssetByID(int nID)
{
	list<CEntity*>::iterator i;

	for (i=m_Entities.begin();i!=m_Entities.end();++i) {
		if ((*i)->m_nID==nID) return (*i);
	}
	return NULL;
}