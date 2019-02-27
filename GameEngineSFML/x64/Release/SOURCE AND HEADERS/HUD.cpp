#include "HUD.h"

namespace SoloStudios {
	
	
	HUD::HUD(GameDataRef data,Clock &clock,LevelManager* levelManager): _data(data),_clock(clock), _mainMenu(data->window),_levelManager(levelManager)
	{
		
		
		_timeText.setFont(_data->assetManager.GetFont("Debugger Font"));
		_timeText.setString("TIME");
		_timeText.setFillColor(sf::Color::Yellow);
		_timeText.setOrigin(_timeText.getGlobalBounds().width / 2, _timeText.getGlobalBounds().height / 2);
		_timeText.setPosition(_timeText.getGlobalBounds().height*2, _timeText.getGlobalBounds().height);
		hudView.setSize(_data->window.getSize().x, _data->window.getSize().y);
		hudView.setCenter(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
		sf::Vector2f viewSize(hudView.getSize());
		viewSize.x =hudView.getSize().x * 1.0f;
		viewSize.y = hudView.getSize().y * 1.0f;
		menuTest.setSize(viewSize);
		//menuTest.setViewport(sf::FloatRect(0.5f, 0.f, 0.25f, 0.25f));

/*		
		sf::FloatRect visibleArea(0.f, 0.f, _data->window.getSize().x, _data->window.getSize().y);
		this->_data->window.setView(sf::View(visibleArea));*/
		initHUD();
	}
	void HUD::loadLevel() {
		
		_levelManager->clearLevel();
		_levelManager->LoadNextLevel();
	}
	void HUD::initHUD() {

		_mainMenu.setSize(Vector2f(150, 500));
		_mainMenu.setPos(Vector2f(100, 100));
		//_mainMenu.setPosition(Vector2f(10, 1000));
		VLayout* layout = new VLayout;
		layout->setSpace(2);
		/*layout->_position.x;*/
		TextButton* newGame = new TextButton("Change Level", _data->assetManager.GetFont("Debugger Font"));
		newGame->setFillColor(Color::Black);
		newGame->onClick=[this](const sf::Event&, Button& button){

			loadLevel();
		};
		
		layout->add(newGame);
		TextButton* hideDebug = new TextButton("Hide Debug Level", _data->assetManager.GetFont("Debugger Font"));
		hideDebug->setFillColor(Color::Blue);
		hideDebug->onClick = [this](const sf::Event&, Button& button) {

			_levelManager->level.hideDebugNodes();
		};
		layout->add(hideDebug);
		TextButton* otro = new TextButton("Test", _data->assetManager.GetFont("Debugger Font"));
		layout->add(otro);
		
		
		_mainMenu.setLayout(layout);

		
	}

	void HUD::HandleInput(Event& event) {
		_mainMenu.processEvent(event);

	}
	void HUD::Draw(float dt) {
		this->_data->window.setView(hudView);
		_data->window.draw(_timeText);
		_mainMenu.draw();
		//_data->window.draw(_mainMenu);
		//this->_data->window.setView(menuTest);
		
		
	}

	void HUD::Update(float dt,float frameTime, float accumulator, float fps) {
		_timeText.setString(string{ "DEBUGGER:  FPS: " +std::to_string(fps)+" T: "+ std::to_string(_clock.getElapsedTime().asSeconds()) + " DT: " +std::to_string(dt)+" FT: " + std::to_string(frameTime)+" AC: "+std::to_string(accumulator) });
	}

}