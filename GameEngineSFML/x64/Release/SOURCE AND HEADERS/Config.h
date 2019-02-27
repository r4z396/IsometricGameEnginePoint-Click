#pragma once
#ifndef CONFIG_HPP
#define CONFIG_HPP
#include "ActionMap.h"
namespace SoloStudios {


	class Config
	{
	public:
		Config() = delete;
		Config(const Config&) = delete;
		Config& operator=(const Config&) = delete;
		enum GuiInputs : int {
			Escape,
		};
		static ActionMap<int> guiInputs;

		static void initialize();

	private:
		

		
		static void initGuiInputs();
	};
}
#endif