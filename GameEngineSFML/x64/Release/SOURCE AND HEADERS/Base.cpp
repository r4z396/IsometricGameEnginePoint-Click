
#include "Manager.h"

using namespace std;
using namespace sf;
using namespace rapidxml;

// ------------------------------------------------

xml_node<>* FindChildNode(xml_node<>* pNode,const char* szName)
{
	for (xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
		if (strcmp(pChild->name(),szName)==0) return pChild;
	}
	return NULL;
}

xml_attribute<>* FindAttribute(xml_node<>* pNode,const char* szName)
{
	for (xml_attribute<>* pAttr = pNode->first_attribute();pAttr!=NULL;pAttr = pAttr->next_attribute())
	{
		if (strcmp(pAttr->name(),szName)==0) return pAttr;
	}
	return NULL;
}

// ------------------------------------------------

CEntity::CEntity()
{
}

void CEntity::Start(CManager *pManager,xml_node<>* pNode)
{
}

void CEntity::Update(RenderWindow* pWindow)
{
}

// ------------------------------------------------

CImage::CImage()
{
	m_nID = 0;
	m_pImage = NULL;
}

CImage::CImage(CImage* pImage)
{
	m_pImage = pImage;
}

void CImage::SetPosition(sf::Vector2f pos)
{
	m_vPos = pos;
}

void CImage::Start(CManager *pManager,xml_node<>* pNode)
{
	
	xml_attribute<>*	pAttr = FindAttribute(pNode,"id");
	if (pAttr!=NULL) m_nID = atoi(pAttr->value());

	pAttr = FindAttribute(pNode,"x");
	if (pAttr!=NULL) m_vPos.x = atof(pAttr->value());
	pAttr = FindAttribute(pNode,"y");
	if (pAttr!=NULL) m_vPos.y = atof(pAttr->value());

	string  file = pManager->m_strAssets + pNode->value();
	if (m_Texture.loadFromFile(file)) {

		m_Sprite.setTexture(m_Texture);

	}

}

void CImage::Update(RenderWindow* pWindow)
{
	m_Sprite.setPosition(m_vPos);
	//m_Sprite.setRotation(45.f);
	m_Sprite.setScale(Vector2f(2.f, 2.f));
	pWindow->draw(m_Sprite);
}