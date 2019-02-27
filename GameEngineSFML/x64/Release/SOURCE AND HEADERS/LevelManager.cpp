#include "Game.h"
#include "rapidxml.hpp"
#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include "ExternalTools.h"
#include "SpriteLevel.h"
#include "SFML/Graphics/Rect.hpp"
/////////////////////////////////////
//TEST
//#include "Manager.h"
using namespace std;

using namespace rapidxml;

namespace SoloStudios {

	
	//CManager	manager;

	LevelManager::LevelManager()
	{
		
	}


	LevelManager::~LevelManager()
	{
	}

	void LevelManager::clearLevel()
	{
		/*delete level.dataLevel;*/
		//level.dataLevel = NULL;
		level.deleteLevel();
	}
	

	void LevelManager::loadGameData(GameDataRef data)
	{

		cout << data;
		_data = data;
	}
	bool LevelManager::checkIfNodeIsClicked(Vector2f temp, RenderWindow& window) {
		if (level.goal == NULL) { 
			for (int x = 0; x < level.m_nWidth; x++) {
				for (int y = 0; y < level.m_nHeight; y++) {
					level.nodeGrid[x][y].positionISO;


					sf::IntRect tempRect(level.nodeGrid[x][y].positionISO.x, level.nodeGrid[x][y].positionISO.y, 32, 32);
							
					if (tempRect.contains((int)temp.x, (int)temp.y)) {
						level.nodeGrid[x][y].goal = true;
						level.goal = &level.nodeGrid[x][y];
						pathToPoint=_pathfinding.searchPath(&level);
						return true;
						break;
					}

				}
		}
		
		}
		return false;
		//// Get the depth value.
		//float nOffX = (float)x / (float)(-1);
		//float nOffY = (float)y / (float)(m_nHeight - 1);
		//float nX = 128.0f + nOffX * (256.0f - 128.0f);
		//float nY = 128.0f + nOffY * (256.0f - 128.0f);


		//// Adjust for Isometric Coordinates.
		//int isoX = (((x)+y) * 64 / 2);
		//int isoY = ((y - x) * 64 / 4);
		//isoX += (400 / 2) - (64 / 2);
		//isoY += (1000 / 2) - (64 / 2);
	}
	sf::Vector2f LevelManager::LoadNextLevel() {


		level.initDialogsSystem(_data->assetManager.GetFont("Debugger Font"));
		/*sf::Thread test()*/
	
		//level.deleteLevel();

		cout << endl << "Next level" << endl;

		cout << "Loading map";
		cout << endl;
		
		//_data->assetManager.test();
		//this->_data->assetManager;
		cout << "Loading map2";
		cout << endl;
		ifstream MyFile("data.xml", ios::binary);
		cout << "Loading map3";
		cout << endl;
		vector<char> buffer((istreambuf_iterator<char>(MyFile)), istreambuf_iterator<char>());
		cout << "Loading map4";
		cout << endl;
		buffer.push_back('\0');
		cout << "Loading map5";
		cout << endl;
		MyFile.close();

		xml_document<>		Doc;
		Doc.parse<0>(&buffer[0]);

		xml_node<>*	pRootNode = Doc.first_node();

		xml_node<>*				pNode;
		xml_node<>*				pChild;
		xml_attribute<>*	pAttr;

		cout << "Loading map6" +currentLevel;
		cout << endl;

		level.entityManager.m_Entities.clear();

		pNode = FindChildNode(pRootNode, "assets");
		if (pNode != NULL) {
			pAttr = FindAttribute(pNode, "path");

			
			cout << "Loading map7"<< level.entityManager.m_strAssets;
			cout << endl;

			if (pAttr != NULL)
				level.entityManager.m_strAssets = pAttr->value();

			cout << "Loading map8";
			cout << endl;
			for (xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
				if (strcmp(pChild->name(), "img") == 0) {
					SpriteLevel *pImage = new SpriteLevel();
					//pImage->m_Sprite.setOrigin(pImage->m_Sprite.getGlobalBounds().width / 2, pImage->m_Sprite.getGlobalBounds().height / 2);
					pImage->Start(&level.entityManager, pChild);//anspersonnnn
					pImage->m_Sprite.setOrigin(pImage->m_Sprite.getGlobalBounds().width / 2, pImage->m_Sprite.getGlobalBounds().height / 2);
					level.entityManager.m_Entities.push_back(pImage);
					cout << endl << "adding to entity manager";
				}
			}
		}
		
		pNode = FindChildNode(pRootNode, "level");
		cout << endl << "Level:" << to_string(currentLevel).c_str();
		pNode = FindChildNodeWithAttribute(pRootNode, "level", to_string(currentLevel).c_str());
		if (pNode != NULL) {
			
			currentLevel++;
			
			

			return level.Init(pNode);
			
		}

		
	}

	sf::Vector2f LevelManager::LoadLevel() {
		level.initDialogsSystem(_data->assetManager.GetFont("Debugger Font"));

		
		
		cout << endl<<"CREATING NEW LEVEL"<< endl;
		
		cout << "Loading map";
		_data->assetManager.test();
		//this->_data->assetManager;
		cout << "Loading map";
		ifstream MyFile("data.xml",ios::binary);
		vector<char> buffer((istreambuf_iterator<char>(MyFile)), istreambuf_iterator<char>());
		buffer.push_back('\0');
		MyFile.close();
		
		xml_document<>		Doc;
		Doc.parse<0>(&buffer[0]);

		xml_node<>*	pRootNode = Doc.first_node();

		xml_node<>*				pNode;
		xml_node<>*				pChild;
		xml_attribute<>*	pAttr;
		

		pNode = FindChildNode(pRootNode,"assets");
		if (pNode!=NULL) {
			pAttr = FindAttribute(pNode,"path");
			
			
			if (pAttr!=NULL) 
				level.entityManager.m_strAssets= pAttr->value();

			for (xml_node<>* pChild = pNode->first_node(); pChild != NULL; pChild = pChild->next_sibling()) {
				if (strcmp(pChild->name(),"img")==0) {
					SpriteLevel *pImage = new SpriteLevel();

					pImage->Start(&level.entityManager,pChild);//anspersonnnn
					pImage->m_Sprite.setOrigin(pImage->m_Sprite.getGlobalBounds().width / 2, pImage->m_Sprite.getGlobalBounds().height / 2);
					level.entityManager.m_Entities.push_back(pImage);
					cout << endl << "adding to entity manager";
				}
			}
		}
		pNode = FindChildNode(pRootNode,"level");
		cout << endl << "Level:" << to_string(currentLevel).c_str();
		pNode = FindChildNodeWithAttribute(pRootNode, "level", to_string(currentLevel).c_str());
		if (pNode!=NULL) {
			//level = new Level();
			currentLevel++;
			return level.Init(pNode);
		}

		
	}


	
}
