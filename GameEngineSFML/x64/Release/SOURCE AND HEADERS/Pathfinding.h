#pragma once
#ifndef PATHFINDING_H
#define PATHFINDING_H
#include <list>
#include "Node.h"
#include "Level.h"
namespace SoloStudios {


	class Pathfinding
	{
	public:
		Pathfinding();
		~Pathfinding();

		int worldWidt;
		int worldHeight;

		Level *currLevel;
		std::vector<Node*> openList;
		std::vector<Node*> closeList;
		std::vector<Node*> finalPath;

		float getFCost(Node* temp);
		bool contains (Node* temp, std::vector<Node*> tempList);
		float getDistance(Node* node1, Node* node2);
		std::vector<Node*> searchPath(Level *currLevel);
		void getPath(Node* node1, Node* node2);
		std::vector<Node*>  getNeighbours(Node* elem);
	};
}

#endif
