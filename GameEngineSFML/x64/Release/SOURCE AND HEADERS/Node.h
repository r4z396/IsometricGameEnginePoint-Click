#pragma once
#ifndef NODE_H
#define NODE_H

#include "SFML/Graphics.hpp"

namespace SoloStudios {


	class Node
	{
	public:
		Node();
		~Node();
		
		sf::Vector2i position;
		sf::Vector2f positionISO;

		//sf::CircleShape shape;

		void init();
		void Draw(sf::RenderWindow* pWindow/*, bool draw*/);

		void setIsoPosition(sf::Vector2f temp);

		bool hideDebug;
		bool goal;
		bool start;
		bool checked;
		bool path;
		float gCost=0;
		float hCost=0;
		float fCost=0;

		/*float getFcost() {
			fCost = gCost + hCost;
			return fCost;
		}*/

		Node* parent=NULL;


	};
}
#endif
