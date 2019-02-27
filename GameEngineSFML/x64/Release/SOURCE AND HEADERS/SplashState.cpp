#include "SplashState.h"
#include <sstream>
#include <iostream>
#include "MainMenuState.h"
namespace SoloStudios {
	SplashState::SplashState(GameDataRef data, LevelManager* levelManager): _data(data), _levelManager(levelManager)
	{

	}


	void SplashState::Init() {
		this->_data->assetManager.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assetManager.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput() {
		Event event;

		while (this->_data->window.pollEvent(event)) {
			if (Event::Closed == event.type) {
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt, float frameTime, float accumulator,float fps) {
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "Changing Scene";
			_data->stateMachine.AddState(StateRef(new MainMenuState(_data,_levelManager)), true);
		}
	}

	void SplashState::Draw(float dt, float frameTime, float accumulator,float fps) {

		this->_data->window.clear(Color::Black);
		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}
}

