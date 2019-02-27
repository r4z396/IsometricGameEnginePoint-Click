#include "Quote.h"


namespace SoloStudios {
	Quote::Quote(sf::Font& font)
	{
	
		_text.setFont(font);

	}


	Quote::~Quote()
	{
	}

	void Quote::Update(sf::RenderWindow* pWindow)
	{
		_text.setPosition(pos);
		_text.getFont();
		pWindow->draw(_text);

	}

}
