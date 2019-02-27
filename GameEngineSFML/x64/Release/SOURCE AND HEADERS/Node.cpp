#include "Node.h"
#include <iostream>

namespace SoloStudios {


	Node::Node()
	{

		goal = false;
		start = false;
		/*shape.setRadius(5.f);
		shape.setFillColor(sf::Color(100, 0, 150));*/
	}


	Node::~Node()
	{
	}

	void Node::init() {
		//shape = new sf::CircleShape(5.f);
		//this->start = false;
		//start = true;
		
	}

	void Node::Draw(sf::RenderWindow* pWindow/*, bool draw*/) {

		//std::cout << "              sadasdasdad        ";
		/*if(draw)
		pWindow->draw(shape);*/
		sf::CircleShape shape(5.f);
		shape.setPosition(positionISO);
		// set the shape color to green
		this;
		if (hideDebug) {


			if (start) {
				shape.setFillColor(sf::Color::Cyan);
			}

			else if (goal) {
				shape.setFillColor(sf::Color::Blue);
			}
			else if (checked) {
				shape.setFillColor(sf::Color::Magenta);
			}
			else if (path) {
				shape.setFillColor(sf::Color::Yellow);
			}
			else
				shape.setFillColor(sf::Color::Red);

			pWindow->draw(shape);
		}
		
	}

	
	void Node::setIsoPosition(sf::Vector2f temp) {
	positionISO = temp;
	//	shape->setPosition(temp);*/
	}
}