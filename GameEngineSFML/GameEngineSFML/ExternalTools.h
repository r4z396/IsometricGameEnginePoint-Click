#pragma once
#ifndef EXTERNALTOOLS_H
#define EXTERNALTOOLS_H
#include "rapidxml.hpp"
#include <iostream>
#include <list>
#include <fstream>
#include <vector>
namespace SoloStudios {


	
		rapidxml::xml_node<>* FindChildNode(rapidxml::xml_node<>* pNode, const char* szName);
		rapidxml::xml_attribute<>* FindAttribute(rapidxml::xml_node<>* pNode, const char* szName);
		rapidxml::xml_node<>* FindChildNodeWithAttribute(rapidxml::xml_node<>* pNode, const char* szName, const char* szAttribute);

	

}
#endif