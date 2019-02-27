#pragma once
#include "State.h"
#include "Game.h"
#include <iostream>
namespace SoloStudios {


	class SplashState :
		public State
	{
	public:
		SplashState(GameDataRef data,LevelManager* levelManager);
		~SplashState();


		void Init();

		void HandleInput();

		void Update(float dt, float frameTime, float accumulator,float fps);
		void Draw(float dt, float frameTime, float accumulator,float fps);
	private:
		GameDataRef _data;
		LevelManager* _levelManager;
		Clock _clock;
		Sprite _background;
	};

}

