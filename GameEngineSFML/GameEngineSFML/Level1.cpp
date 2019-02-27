#include "Level1.h"

using namespace std;
using namespace sf;
using namespace rapidxml;

Clock timing;

CLevel::CLevel()
{
	m_nWidth = m_nHeight = 0;
	m_pLevel = NULL;
	m_pManager = NULL;  
}

CLevel::~CLevel()
{
	if (m_pLevel!=NULL) free(m_pLevel);
}

void CLevel::Start(CManager *pManager,xml_node<>* pNode)
{
	m_pManager = pManager;

	xml_attribute<>*	pAttr = FindAttribute(pNode,"id");
	if (pAttr!=NULL) m_nID = atoi(pAttr->value());

	pAttr = FindAttribute(pNode,"width");
	if (pAttr!=NULL) m_nWidth = atoi(pAttr->value());
	pAttr = FindAttribute(pNode,"height");
	if (pAttr!=NULL) m_nHeight = atoi(pAttr->value());

	m_pLevel = (char*)malloc(m_nWidth*m_nHeight);

	int j=0;
	for (int i=0;i<strlen(pNode->value());i++) {
		if (pNode->value()[i]>32) {
			m_pLevel[j] = pNode->value()[i]-48;
			j++;
		}
	}
}

void CLevel::Update(RenderWindow* pWindow)
{
	for (int x = m_nWidth; x >0; x--) {
		for  (int y = 0; y < m_nHeight; y++) {


			int id = m_pLevel[y*m_nWidth+x];
			CImage* pItem = (CImage*)m_pManager->GetAssetByID(id);
			if (pItem!=NULL) {


				// Get the depth value.
				float nOffX = (float)x / (float)( - 1);
				float nOffY = (float)y / (float)(m_nHeight - 1);
				float nX = 128.0f + nOffX * (256.0f - 128.0f);
				float nY = 128.0f + nOffY * (256.0f - 128.0f);
				
				
					// Adjust for Isometric Coordinates.
					int isoX = (((x ) + y) * 64 / 2);
					int isoY = ((y - x) * 64 / 4);
					isoX += (1500/ 2) - (64 / 2);
					isoY += (1000 / 2) - (64 / 2);
					pItem->SetPosition(Vector2f(isoX, isoY));
					pItem->Update(pWindow);
				//
				////pItem->SetPosition(Vector2f(x*32,y*32));
				///*Vector2f temp = Vector2f(x * 32, y * 32);
				//temp.x= x - y;
				//temp.y= (x + y) / 2;*/
				//int isoX = ((x - y) * 64/ 4);
				//int isoY = ((y + x) * 32 / 2);
				//isoX += (4000 / 4) - (64 / 2);
				//isoY += (100 / 2) - (32/ 2);
				//pItem->SetPosition(Vector2f(isoX,isoY));
				//pItem->Update(pWindow);
			}
		}
	}
}

