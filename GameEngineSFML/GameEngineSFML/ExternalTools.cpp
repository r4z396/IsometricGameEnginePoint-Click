#include "ExternalTools.h"

namespace SoloStudios {

	rapidxml::xml_node<>* FindChildNode(rapidxml::xml_node<>* pNode, const char* szName)
	{
		for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
			if (strcmp(pChild->name(), szName) == 0) return pChild;
		}
		return NULL;
	}

	rapidxml::xml_node<>* FindChildNodeWithAttribute(rapidxml::xml_node<>* pNode, const char* szName, const char* szAttribute)
	{
		rapidxml::xml_attribute<>* pAttr;
		for (rapidxml::xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
			pAttr = pChild->first_attribute();
			if (strcmp(pChild->name(), szName) == 0&& strcmp(pAttr->value(),szAttribute)==0) return pChild;
			std::cout << std::endl << pChild->name() << "  " << pAttr->name();
		}
		std::cout << "no found";
		return NULL;
	}

	rapidxml::xml_attribute<>* FindAttribute(rapidxml::xml_node<>* pNode, const char* szName)
	{
		for (rapidxml::xml_attribute<>* pAttr = pNode->first_attribute(); pAttr != NULL; pAttr = pAttr->next_attribute())
		{
			if (strcmp(pAttr->name(), szName) == 0) return pAttr;
		}
		return NULL;
	}
}

