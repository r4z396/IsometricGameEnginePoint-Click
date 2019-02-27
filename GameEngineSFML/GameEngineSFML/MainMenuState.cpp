#include "MainMenuState.h"
#include"GameState.h"
namespace SoloStudios {

	MainMenuState::MainMenuState(GameDataRef data ,LevelManager* levelManager): _data(data), _levelManager(levelManager)
	{
	}

	void MainMenuState::Init() {

		//Textures
		this->_data->assetManager.LoadTexture("Main Menu Background", MENU_SCENE_BACKGROUND_FILEPATH);
		this->_data->assetManager.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assetManager.LoadTexture("Menu Play Button", MENU_PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assetManager.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assetManager.GetTexture("Game Title"));
		
		_playButton.setTexture(this->_data->assetManager.GetTexture("Menu Play Button"));
		_playButton.scale(0.5f, 0.5f);
		_playButton.setColor(Color::Cyan);

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));

		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().width / 2));
	}

	void MainMenuState::HandleInput() {
		Event event;

		while (this->_data->window.pollEvent(event)) {
			if (Event::Closed == event.type) {
				this->_data->window.close();
			}

			if (_data->inputManager.IsSpriteClick(_playButton, Mouse::Left, _data->window)) {
				cout << "Click play button";
				_data->stateMachine.AddState(StateRef(new GameState(_data,_levelManager)), true);
			}
		}
	}

	void MainMenuState::Update(float dt, float frameTime, float accumulator,float fps) {
		
	}

	void MainMenuState::Draw(float dt, float frameTime, float accumulator,float fps) {

		this->_data->window.clear(Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}


