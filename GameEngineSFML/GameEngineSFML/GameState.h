#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "State.h"
#include "Game.h"
#include <iostream>
#include "HUD.h"
#include "Player.h"
namespace SoloStudios {


	class GameState :
		public State, ActionTarget<int>
	{
	public:
		GameState(GameDataRef data, LevelManager* levelManager);
		~GameState();


		void Init();

		void HandleInput();

		void Update(float dt, float frameTime, float accumulator,float fps);
		void Draw(float dt, float frameTime, float accumulator,float fps);
	private:

		vector <Node*> path;
		bool movePlayer = false;
		int indexPosPath;

		float getDistance(Vector2f a, Vector2f b);

		
		void hideInfoHud();
		GameDataRef _data;

		CircleShape test;
		Clock _clock;
		Sprite _background;
		Sprite _test;
		LevelManager* _levelManager;
		//Content
		HUD *hud;
		View gameView;
		View backgroundView;

		Player* _player;
	};

}
#endif

