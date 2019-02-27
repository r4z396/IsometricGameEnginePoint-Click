#include "Pathfinding.h"
#include <cmath>   

namespace SoloStudios {


	Pathfinding::Pathfinding()
	{
	}


	Pathfinding::~Pathfinding()
	{
	}
	std::vector < Node*> Pathfinding::getNeighbours(Node* elem) {
		
			//console.log('getting neighbours');
		std::vector<Node*> neighbours;
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					
					/*(x == 0 && y == 0) || (x != 0 && y != 0)*/
					if ((x != 0 || y != 0)) {
						
						int checkX = elem->position.x + x;
						int checkY = elem->position.y + y;
						std::cout << std::endl<<checkX << " " << checkY;
								if (checkX >= 0 && checkX < (worldWidt) && checkY >= 0 && checkY < (worldHeight)) {
									neighbours.push_back(&currLevel->nodeGrid[checkX][checkY]);
									std::cout << std::endl << "added neighbour "<<checkX<<" "<<checkY;

									currLevel->nodeGrid[checkX][checkY].checked = true;
								}
						}
						
					

				}
			}
			return neighbours;
		

	}

	
	float Pathfinding::getFCost(Node* temp) {
		return (temp->hCost + temp->gCost);
	}

	bool Pathfinding::contains(Node* temp, std::vector<Node*> tempList) {
		

		if(std::find(tempList.begin(), tempList.end(), temp) != tempList.end()) {
			return true;
			}
		else {

			return false;
		}
		
	}
	float Pathfinding::getDistance(Node* node1, Node* node2) {
		float distanceX = abs(node1->position.x - node2->position.x);
		float distanceY = abs(node1->position.y - node2->position.y);

		if (distanceX > distanceY) {
			return 14 * distanceY + (10 * distanceX - distanceY);
		}
		else {
			return 14 * distanceX + (10 * distanceY - distanceX);
		}

	}
	void Pathfinding::getPath(Node* node1, Node* node2) {

		Node* tempNode =currLevel->goal;
		while (tempNode != currLevel->start) {
			//console.log("añadiendo a path nodo");
			finalPath.push_back(tempNode);
			tempNode = tempNode->parent;
		}
		std::reverse(finalPath.begin(), finalPath.end());
		for (Node* i : finalPath)
		{
			i->path = true;
			i->checked = false;
		}
	}
	
	
	std::vector <Node*> Pathfinding::searchPath(Level *currLevel) {

		this->currLevel = currLevel;
		worldWidt = currLevel->m_nWidth;
		worldHeight = currLevel->m_nHeight;

		openList.push_back(currLevel->start);
		std::cout <<std::endl<< "SEARCHING";
		while (openList.size() > 0) {
			std::cout << std::endl << "loop";
			std::cout << std::endl << openList.size();
			Node* currentNode = openList.front();

			for (int i = 0; i < openList.size(); i++) {
				std::cout << "BUSCANDO ";
				//console.log(getFCost(openList[i]));
				if (getFCost(openList[i]) < getFCost(currentNode) || getFCost(openList[i]) == getFCost(currentNode) && openList[i]->hCost < currentNode->hCost) {
					currentNode = openList[i];

					

				}
				std::cout << "BUSCANDO 0";
				//openList.erase(std::find(openList.begin(), openList.end(), currentNode));
				openList.erase(std::remove(openList.begin(), openList.end(), currentNode), openList.end());
				std::cout << "BUSCANDO 01";
				closeList.push_back(currentNode);
				std::cout << "BUSCANDO 02";
				std::cout << std::endl << currentNode->position.x << " " << currLevel->goal->position.x;
				if (currentNode == currLevel->goal) {
					/*/lastSearchSpan.innerHTML = new Date().getTime() - start;
					console.log('Finalizado');
					getPath(startNode, goalNode);
					return;*/

					std::cout << "ENCONTRADOOO";
					getPath(currLevel->start, currLevel->goal);

					return finalPath;
				}

				std::vector<Node*> neighbours = getNeighbours(currentNode);
				

				std::cout << "BUSCANDO 1";



				for (int i = 0; i < neighbours.size(); i++)
				{

					std::cout << "BUSCANDO 2";
					if ( contains(neighbours[i],closeList) ) {


					}
					else {

						std::cout << "BUSCANDO 3";
						float newCostToNeighbour = currentNode->gCost + getDistance(currentNode, neighbours[i]);
						//check and multiply for height not implemented yet
						/*if (currentNode.height != neighbours[i].height)
							newCostToNeighbour += (20 * neighbours[i].height);*/


						if (newCostToNeighbour < neighbours[i]->gCost || !contains( neighbours[i], openList)) {



							neighbours[i]->gCost = newCostToNeighbour;
							neighbours[i]->hCost = getDistance(neighbours[i], currLevel->goal);
							neighbours[i]->parent = currentNode;
							

							if (!contains( neighbours[i],openList)) {
								openList.push_back(neighbours[i]);



								

							}
						}
					}



				}
				

			}


		}
		std::cout << "NOOOOOOOOOOOOOOOOOOO ENCONTRADOOO";
	}



}