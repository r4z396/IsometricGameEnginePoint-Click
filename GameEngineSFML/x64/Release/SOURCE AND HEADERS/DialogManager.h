#pragma once
#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H

#include <iostream>
#include <list>

#include <fstream>
#include "Entity.h"
#include "rapidxml.hpp"
#include "ExternalTools.h"
#include "Quote.h"

namespace SoloStudios {

class DialogManager: public Entity
	{
	public:
		DialogManager(sf::Font& font);
		~DialogManager();

		void init(sf::Font& font);
		void loadDialogsLevel();
		void Update(sf::RenderWindow* pWindow);

	private:
		sf::Font& font;
		int numbQuotes=0;
		int indexQuote=0;
		
		std::vector <Quote*> quoteList;
		sf::Clock timer_clock;
		float time;

	};


}
#endif
