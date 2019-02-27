#ifndef GAME_H
#define GAME_H



#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

#include "Level.h"
#include "Pathfinding.h"
#include "DEFINITIONS.h"

using namespace std;
using namespace sf;

namespace SoloStudios {

	
	
	struct  GameData
	{
		StateMachine stateMachine;
		RenderWindow window;
		//RenderWindow windowHUD;
		AssetManager assetManager;
		InputManager inputManager;
		/*LevelManager levelManager;*/
		
	};
	//pointer for navigation through gamedata
	
	typedef shared_ptr<GameData> GameDataRef;
	


	//////////////////////////////////////////////////////////////////////////////////////////
	////////THIS DECLARATION OF LEVELMANAGER IS FOR AVOIDING CYRCULAR DEPENDECY
	///////TEMPORARY UNTIL I FIND A BETTER SOLUTION, OR I CHANGE THE DESIGN OF THE ENGINE
	class LevelManager
	{
	public:
		LevelManager();
		~LevelManager();

		void loadGameData(GameDataRef data);
		sf::Vector2f LoadLevel();
		sf::Vector2f LoadNextLevel();
		bool checkIfNodeIsClicked(Vector2f temp, RenderWindow& window);
		
		void clearLevel();
		Level level;
		vector<Node*> pathToPoint;
		Pathfinding _pathfinding;
		//EntityManager entityManager;
		
	private:
		int currentLevel=1;
		GameDataRef _data;
		


	};
	///////////////////////////////////////////////////////////////////////////////////////////



	class Game {

	public:
		Game(int width, int height, string title);
		GameDataRef _data = make_shared<GameData>();

		//Test LevelManager
		LevelManager levelManager;
		//GameDataRef _data = std::shared_ptr<GameData>(new GameData);
		//std::shared_ptr<int> p = std::shared_ptr<int>(new int);
		

	private:
		const float dt = 1.0f / 60.0f;
		Clock _clock;
		

		void Run();

	};


}

#endif