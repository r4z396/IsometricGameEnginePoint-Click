#include "GameState.h"
#include "SplashState.h"
#include <sstream>
#include <iostream>
#include "MainMenuState.h"
#include "LevelManager.h"
#include "Config.h"
#include "SFML/Graphics.hpp"

namespace SoloStudios {
	//Zoom
	float zoomValue = 1;
	sf::Vector2f oldPos;
	bool moving = false;

	GameState::GameState(GameDataRef data, LevelManager* levelManager) : ActionTarget(Config::guiInputs), _data(data), _levelManager(levelManager)
	{
		
	}


	void GameState::hideInfoHud() {

	}
	void GameState::Init() {

		
		gameView.setSize(_data->window.getSize().x, _data->window.getSize().y);
		backgroundView.setSize(_data->window.getSize().x, _data->window.getSize().y);
		backgroundView.setCenter(_data->window.getSize().x / 2, _data->window.getSize().y / 2);

		_levelManager->loadGameData(_data);
		
		

		_data->assetManager.LoadFont("Debugger Font", DEBUGGER_FONT_FILEPATH);

		hud = new HUD(_data, _clock,_levelManager);
		this->_data->assetManager.LoadTexture("Game State Background", GAME_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assetManager.GetTexture("Game State Background"));

		//Load textures tiles
		this->_data->assetManager.LoadTexture("Grass Tile", GRASS_TILE_FILEPATH);
		this->_data->assetManager.LoadTexture("Dirt Tile", DIRT_TILE_FILEPATH);
		_background.setColor(Color::Magenta);
	
		cout << endl<<" SIZE BACKGROUNDVIEW" << endl <<backgroundView.getSize().x << " " << backgroundView.getSize().y;
		cout << endl<< " middle BACKGROUNDVIEW" << endl << backgroundView.getSize().x/2 << " " << backgroundView.getSize().y/2;
		cout << endl<< " POS BACKGROUNDIMG" << endl << _background.getPosition().x << " " << _background.getPosition().y;
		cout << endl << " SIZE BACKGROUNDimg" << endl << _background.getGlobalBounds().width << " " << _background.getGlobalBounds().height;
		cout << endl << " middle BACKGROUNDIMG" << endl << _background.getGlobalBounds().width/2 << " " << _background.getGlobalBounds().height/2;
		cout << endl << " origin BACKGROUNDIMG" << endl << _background.getOrigin().x << " " <<  _background.getOrigin().y;
		
		

		//Player SETUP
		this->_data->assetManager.LoadTexture("Player Sprite Sheet Idle", PLAYER_SPRITE_IDLE_SHEET_FILEPATH);
		this->_data->assetManager.LoadTexture("Player Sprite Sheet Walk", PLAYER_SPRITE_WALK_SHEET_FILEPATH);
		_player = new Player(&this->_data->assetManager.GetTexture("Player Sprite Sheet Idle"), Vector2u(11, 1), 0.3f);
		//_test.setTexture(this->_data->assetManager.GetTexture("Player Sprite Sheet"));
		_player->_playerRectangle.setTexture(&this->_data->assetManager.GetTexture("Player Sprite Sheet Idle"));
		_player->spriteSheetIdle = &this->_data->assetManager.GetTexture("Player Sprite Sheet Idle");
		_player->spriteSheetWalk = &this->_data->assetManager.GetTexture("Player Sprite Sheet Walk");
		_player->_playerRectangle.setOrigin(_player->_playerRectangle.getGlobalBounds().width / 2, _player->_playerRectangle.getGlobalBounds().height / 2);
		_player->_playerRectangle.setPosition(_levelManager->LoadLevel());
		
	}

	void GameState::HandleInput() {
		this->_data->window.setView(gameView);
		Event event;

		while (this->_data->window.pollEvent(event)) {

			
			if (Event::Closed == event.type) {
				this->_data->window.close();
			}

			hud->HandleInput(event);
			_player->HandleInput(event);
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
				this->_data->window.setView(sf::View(visibleArea));
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{

				if (moving)
					break;

				// Determine the scroll direction and adjust the zoom level
				// Again, you can swap these to invert the direction
				if (event.mouseWheelScroll.delta <= -1)
					zoomValue = std::min(2.f, zoomValue + .1f);
				else if (event.mouseWheelScroll.delta >= 1)
					zoomValue = std::max(.5f, zoomValue - .1f);

				// Update our view
				gameView.setSize(this->_data->window.getDefaultView().getSize()); // Reset the size
				gameView.zoom(zoomValue); // Apply the zoom level (this transforms the view)


				/*this->_data->window.setView(gameView);*/
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
					std::cout << "wheel type: vertical" << std::endl;
				else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
					std::cout << "wheel type: horizontal" << std::endl;
				else
					std::cout << "wheel type: unknown" << std::endl;
				std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
				std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
				std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					
					
					cout << "soltado";
					moving = false;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					test.setRadius(5.f);
					test.setPosition(Vector2f( Mouse::getPosition(_data->window).x,Mouse::getPosition(_data->window).y));
					//CHECK IF CLICKED IN GRIDNODE
					//_levelManager->checkIfNodeIsClicked(Vector2f(Mouse::getPosition(_data->window).x, Mouse::getPosition(_data->window).y), _data->window);
					
					
					moving = true;
					oldPos = this->_data->window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
					
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;


				}
			}
			if(event.type ==  sf::Event::MouseMoved)
			{
				// Ignore mouse movement unless a button is pressed (see above)
				if (!moving)
					break;

				// Determine the new position in world coordinates
				const sf::Vector2f newPos =this->_data-> window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				// Determine how the cursor has moved
				// Swap these to invert the movement direction
				const sf::Vector2f deltaPos = oldPos - newPos;
				cout <<endl << "  y   " << deltaPos.y;
				// Move our view accordingly and update the window
				
				gameView.setCenter(gameView.getCenter() + deltaPos);

				this->_data->window.setView(gameView);

				// Save the new position as the old one
				// We're recalculating this, since we've changed the view
				oldPos = this->_data->window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				
			}
			
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					///*sf::View view = this->_data->window.getDefaultView();*/
					//zoomValue -= 0.05;
					///*view.zoom(zoomValue);
					//this->_data->window.setView(view);*/
					//gameView.zoom(zoomValue);
					if (_levelManager->checkIfNodeIsClicked(this->_data->window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)), _data->window)) {
						//movePlayerToPosition(_levelManager->pathToPoint);
						_player->moving();
						path = _levelManager->pathToPoint;
						movePlayer = true;
					}
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
		}
	}

	float GameState::getDistance(Vector2f a, Vector2f b) {
		//float distx = a.x - b.y; // distx can be negative.
		//float disty = a.y - b.y; // disty can be negative.

		//


		//
		//return std::sqrt(distx * distx + disty * disty);
		return sqrt(pow(b.x - a.x, 2) +
			pow(b.y - a.y, 2) * 1.0);
		
	}
	void GameState::Update(float dt, float frameTime, float accumulator,float fps) {
		

		if (movePlayer) {

			
			if (getDistance( _player->_playerRectangle.getPosition(), path[indexPosPath]->positionISO)<1) {
				if (indexPosPath < path.size()-1) {
					indexPosPath++;
					cout << endl << "ONE MORE ";
				}				
				else {
					movePlayer = false;
					indexPosPath = 0;
					_player->stop();
					_levelManager->level.initNodeGrid();
					_levelManager->level.nodeGrid[path.back()->position.x][path.back()->position.y].start = true;
					
					_levelManager->level.start =& _levelManager->level.nodeGrid[path.back()->position.x][path.back()->position.y];
					_levelManager->level.goal = NULL;
					_levelManager->pathToPoint.clear();
					_levelManager->_pathfinding.closeList.clear();
					_levelManager->_pathfinding.openList.clear();
					_levelManager->_pathfinding.finalPath.clear();
					_levelManager->_pathfinding.currLevel=NULL;

					cout << endl << "WE ARRIVE TO POINT ";
					
				}
					
			}
			else {


				_player->_playerRectangle.setPosition(_player->_playerRectangle.getPosition() + (path[indexPosPath]->positionISO - _player->_playerRectangle.getPosition()) * dt*2.f);
				//cout << endl << "moviendo";
			}
		}
		

		
		hud->Update(dt, frameTime,accumulator,fps);
		_player->Update(0, dt);

		
	}


	void GameState::Draw(float dt, float frameTime, float accumulator,float fps) {


		this->_data->window.clear(Color::Red);


		////DRAW BACKGROUND
		this->_data->window.setView(backgroundView);
		this->_data->window.draw(this->_background);
	


		//////DRAW GAME		
		this->_data->window.setView(gameView);	
		
		this->_levelManager->level.Update(&this->_data->window);
		this->_data->window.draw(_player->_playerRectangle);
		sf::CircleShape shape(5.f);

		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));
		shape.setPosition(gameView.getCenter());
		this->_data->window.draw(shape);
		
		
		//this->_data->window.draw(_test);
		//DRAW HUD
		hud->Draw(dt);
		this->_data->window.draw(test);
		
		this->_data->window.display();


		this->_data->window.setView(gameView);
		}
}

