#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "Widget.h"
#include <functional>
namespace SoloStudios {

	class Button : public Widget
	{
	public:
		using FuncType = std::function<void(const sf::Event& event, Button& self)>;
		static FuncType defaultFunc;
		Button(Widget* parent = nullptr);

		virtual ~Button();
		FuncType onClick;

	protected:
		virtual bool processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
		virtual void onMouseEntered();
		virtual void onMouseLeft();

	private:
		enum Status { None = 0, Hover = 1 };
		int _status;
	};
	//#include <string.h>
	//#include <SFML/Graphics.hpp>
	//class Button {
	//public:
	//	Button(sf::Texture* normal, sf::Texture* clicked, std::string, sf::Vector2f location);
	//	void checkClick(sf::Vector2f);
	//	void setState(bool);
	//	void setText(std::string);
	//	bool getVar();
	//	sf::Sprite* getSprite();
	//	sf::Text * getText();
	//private:
	//	sf::Sprite normal;
	//	sf::Sprite clicked;
	//	sf::Sprite* currentSpr;
	//	sf::Text String;
	//	bool current;
	//};
}
#endif