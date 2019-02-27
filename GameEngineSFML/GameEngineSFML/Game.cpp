#include "Game.h"
#include "SplashState.h"
#include "LevelManager.h"
namespace SoloStudios {
	Game::Game(int width, int height, string title) {

		
		_data->window.create(VideoMode(width, height), title, Style::Default | Style::Titlebar);
		

		_data->stateMachine.AddState(StateRef(new SplashState(this->_data, &levelManager)));

		this->Run();
	}

	void Game::Run() {
		float newTime, frameTime, interpolation;
		float currenTime = this->_clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;

		float frames = 0.0f;

		float fps = 0;

		sf::Clock clock;
		while (this->_data->window.isOpen()) {

			this->_data->stateMachine.ProcessStateChanges();
			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currenTime;
			fps = frames / frameTime;
			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			currenTime = newTime;
			accumulator += frameTime;
			while (accumulator >= dt) {
				sf::Time time=clock.getElapsedTime();
				fps = 1.0f / time.asSeconds();
				this->_data->stateMachine.GetActiveState()->HandleInput();
				this->_data->stateMachine.GetActiveState()->Update(dt,frameTime,accumulator,fps);
				accumulator -= dt;

				clock.restart().asSeconds();
			}

			interpolation = accumulator / dt;

			this->_data->stateMachine.GetActiveState()->Draw(interpolation,frameTime,accumulator,fps);
			frames += 1;
		}
	}
}