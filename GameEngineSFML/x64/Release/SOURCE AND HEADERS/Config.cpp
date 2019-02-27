#include "Config.h"

namespace SoloStudios {
	ActionMap<int> Config::guiInputs;

	void Config::initialize()
	{
		
		initGuiInputs();

		

	}

	void Config::initGuiInputs()
	{
		//guiInputs.map(GuiInputs::Escape, Action(sf::Keyboard::Escape, Action::Type::Pressed));
	}

}