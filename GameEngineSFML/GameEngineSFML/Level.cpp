#include "Level.h"


using namespace std;
using namespace sf;
using namespace rapidxml;

namespace SoloStudios {

	void Level::deleteLevel() {
		canDraw = false;
		for (int i = 0; i < m_nWidth; i++)
			delete[] nodeGrid[i];
		delete[] nodeGrid; // this needs to be done last

		


	}

	sf::Vector2f Level::Init(/*EntityManager *pManager,*/rapidxml::xml_node<>* pNode) {
		
		
		canDraw = false;
		/*entityManager = pManager;*/

		xml_attribute<>*	pAttr = FindAttribute(pNode, "id");
		if (pAttr != NULL) m_nID = atoi(pAttr->value());

		pAttr = FindAttribute(pNode, "width");
		if (pAttr != NULL) m_nWidth = atoi(pAttr->value());
		pAttr = FindAttribute(pNode, "height");
		if (pAttr != NULL) m_nHeight = atoi(pAttr->value());

		
		//Creating NodeGrid

		nodeGrid = new Node*[m_nWidth](); // allocate an array of 10 int pointers — these are our rows
		//nodeGridShape = new sf::CircleShape*[m_nWidth]; // allocate an array of 10 int pointers — these are our rows
		for (int count = 0; count < m_nWidth; ++count) {
			nodeGrid[count] = new Node[m_nHeight](); // these are our columns
			//nodeGridShape[count] = new CircleShape[m_nHeight]; // these are our columns
		}

		
			
		cout << endl << "PRINT LEVEL NODEGRID" << endl;
		for (int x =0 ; x < m_nWidth; x++) {
			
			for (int y = 0; y < m_nHeight; y++)
			{

				cout << "O";
			
			}
			cout << endl;
		}

		cout << endl;
		cout << endl;
		
		 start = NULL;
		 goal = NULL;

		//Save memorie for the map
		dataLevel = (char*)malloc(m_nWidth*m_nHeight);
		int j = 0;
		for (int i = 0; i <= strlen(pNode->value()); i++) {
			if (pNode->value()[i] > 32) {
				dataLevel[j] = pNode->value()[i] - 48;
				j++;
			}
		}  
		
		
		//print level in console
		cout << endl;
		for (int x = m_nWidth; x > 0; x--) {
			for (int y = 0; y < m_nHeight; y++) {


				
				


					cout << "X";
					if (x == 2 && y == 2 ) {
					// Get the depth value.
					float nOffX = (float)x / (float)(-1);
					float nOffY = (float)y / (float)(m_nHeight - 1);
					float nX = 128.0f + nOffX * (256.0f - 128.0f);
					float nY = 128.0f + nOffY * (256.0f - 128.0f);


					// Adjust for Isometric Coordinates.
					int isoX = (((x)+y) * 64 / 2);
					int isoY = ((y - x) * 64 / 4);
					isoX += (400 / 2) - (64 / 2);
					isoY += (1000 / 2) - (64 / 2);
					
					//CALCULATE POSITION OF PLAYER AND RETURN IT
					initNodeGrid();
						startPositionPlayer = Vector2f(isoX, isoY);
						nodeGrid[x][y].start = true;
						start = &nodeGrid[x][y];
						cout <<endl<<"START POSITION OF PLAYER "<< startPositionPlayer.x << "  " << startPositionPlayer.y<<endl;
						firstLoopLevelInit = true;
						canDraw = true;
						//canDraw = false;
						cout << "--------------";
						
						dialogManager->loadDialogsLevel();
						return startPositionPlayer;
					}
					//nodeGrid[y][x].start = false;
				
			}
			cout << endl;
		}



	


	}
	void Level::initNodeGrid() {

		for (int x = 0; x < m_nWidth; x++) {
			for (int y =0; y < m_nHeight; y++) {
					
				nodeGrid[x][y].position = Vector2i(x, y);
				nodeGrid[x][y].start = false;
				nodeGrid[x][y].goal = false;
				nodeGrid[x][y].checked = false;
				nodeGrid[x][y].path = false;
				nodeGrid[x][y].parent=NULL;
				nodeGrid[x][y].fCost = 0;
				nodeGrid[x][y].gCost = 0;
				nodeGrid[x][y].hCost = 0;
				

			}
			
		}
	}
	void Level::initDialogsSystem(sf::Font& font) {
		dialogManager = new DialogManager(font);
		cout << "fjekvonjkefnvjlenvk";
		
	}

	void Level::hideDebugNodes() {

		for (int x = 0; x < m_nWidth; x++) {
			for (int y = 0; y < m_nHeight; y++) {

				

				nodeGrid[x][y].hideDebug =! nodeGrid[x][y].hideDebug;


			}

		}
	}

	Level::Level()
	{

		m_nWidth = m_nHeight = 0;
		dataLevel = NULL;
		//entityManager = NULL;
		canDraw = false;
	}


	Level::~Level()
	{
		///*if (dataLevel != NULL)*/ free(dataLevel);
	}



	void Level::Update(RenderWindow* pWindow)
	{

		
		if (canDraw) {
				
			
			


			for (int x = m_nWidth-1; x >=0; x--) {
			//for (int x = 0 ; x<m_nWidth; x++) {
				
				for (int y = 0; y < m_nHeight; y++) {
					//for (int y = m_nHeight-1; y >=0; y--) {

				


					int id = dataLevel[y*m_nWidth + x];
					SpriteLevel* pItem = (SpriteLevel*)entityManager.GetAssetByID(id);
					//cout <<endl <<"width" << pItem->m_Sprite.getGlobalBounds().width;
					if (pItem != NULL) {


						// Get the depth value.
						float nOffX = (float)x / (float)(-1);
						float nOffY = (float)y / (float)(m_nHeight - 1);
						float nX = 128.0f + nOffX * (256.0f - 128.0f);
						float nY = 128.0f + nOffY * (256.0f - 128.0f);


						// Adjust for Isometric Coordinates.
						int isoX = (((x)+y) * 64 / 2);
						int isoY = ((y - x) * 64 / 4);
						isoX += (400 / 2) - (64 / 2);
						isoY += (1000 / 2) - (64 / 2);
						pItem->SetPosition(Vector2f(isoX, isoY));
						pItem->Update(pWindow);
						
						nodeGrid[x][y].setIsoPosition(Vector2f(isoX, isoY));


						if (nodeGrid[x][y].hideDebug) {
							sf::RectangleShape rectangle;
							rectangle.setSize(sf::Vector2f(32, 32));
							//rectangle.setOutlineColor(sf::Color::Red);
							rectangle.setFillColor(Color::Color(0, 0, 0, 0));
							rectangle.setOutlineThickness(1);
							rectangle.setPosition(isoX, isoY);
							rectangle.rotate(45);
							rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
							nodeGrid[x][y].Draw(pWindow/*,drawNodeGrid*/);
							pWindow->draw(rectangle);
						}
						
						if (x == 1 && y == 1 && firstLoopLevelInit) {
							startPositionPlayer = Vector2f(isoX, isoY);
							//cout << startPositionPlayer.x << "  " << startPositionPlayer.y;
							firstLoopLevelInit = false;
						}
						

					




						//Draw Node

					//cout << endl<<x<<" X "<<y<<" Y";

					//nodeGrid[y][x].position.x = x;
					//nodeGrid[y][x].position.y = y;

						
						//nodeGridShape[y][x].setPosition(nodeGrid[y][x].positionISO);
						



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
					/*cout << endl;*/


				}

			}


			dialogManager->Update(pWindow);
		}
	}

}
