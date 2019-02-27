#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include "State.h"
#include "Game.h"
#include <iostream>
namespace SoloStudios {

	class MainMenuState :
		public State
	{
	public:
		MainMenuState(GameDataRef data,LevelManager* levelManager);
		

		void Init();

		void HandleInput();

		void Update(float dt, float frameTime, float accumulator,float fps);
		void Draw(float dt, float frameTime, float accumulator,float fps);
	private:
		GameDataRef _data;
		LevelManager* _levelManager;

		//Srpites 
		Sprite _background;
		Sprite _title;
		Sprite _playButton;
	};

}
#endif

