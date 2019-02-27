#pragma once
#ifndef HUD_H
#define HUD_H
#include "Game.h"
#include "HUDIncludes.h"
namespace SoloStudios{
	class HUD
	{
	public:
		HUD(GameDataRef data, Clock &clock,LevelManager *levelManager);
		
		void initHUD();
		void Draw(float dt);
		void Update(float dt, float frameTime, float accumulator,float fps);
		void HandleInput(Event& event);
		void loadLevel();
		Frame _mainMenu;
		LevelManager* _levelManager;
		enum GuiInputs : int {
			Escape,
		};
		static ActionMap<int> guiInputs;

	private:
		
		GameDataRef _data;
		Clock _clock;
		sf::Text _timeText;
		
		View hudView;
		View menuTest;
	};
}

#endif
