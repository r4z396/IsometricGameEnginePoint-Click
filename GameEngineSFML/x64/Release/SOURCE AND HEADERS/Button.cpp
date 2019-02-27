
#include "Button.h"

namespace SoloStudios {
	void Button::onMouseEntered() {}
	void Button::onMouseLeft() {}
	Button::Button(Widget* parent) : Widget(parent), onClick(defaultFunc), _status(Status::None) {}
	Button::FuncType Button::defaultFunc = [](const sf::Event&, Button&)->void {};

	Button::~Button() {}
	bool Button::processEvent(const sf::Event& event, const
		sf::Vector2f& parent_pos)
	{
		bool res = false;
		if (event.type == sf::Event::MouseButtonReleased)
		{
			const sf::Vector2f pos = _position + parent_pos;
			const sf::Vector2f size = getSize();
			sf::FloatRect rect;
			rect.left = pos.x;
			rect.top = pos.y;
			rect.width = size.x;
			rect.height = size.y;
			if (rect.contains(event.mouseButton.x, event.mouseButton.y))
			{
				onClick(event, *this);
				res = true;
				std::cout << "clickButton";
			}
		}
		else if (event.type == sf::Event::MouseMoved) {
			const sf::Vector2f pos = _position + parent_pos;
			const sf::Vector2f size = getSize();
			sf::FloatRect rect;
			rect.left = pos.x;
			rect.top = pos.y;
			rect.width = size.x;
			rect.height = size.y;
			int old_status = _status;
			_status = Status::None;
			const sf::Vector2f
				mouse_pos(event.mouseMove.x, event.mouseMove.y);
			if (rect.contains(mouse_pos))
				_status = Status::Hover;
			if ((old_status & Status::Hover) and not (_status &
				Status::Hover))
				onMouseLeft();
			else if (not (old_status & Status::Hover) and (_status &
				Status::Hover))
				onMouseEntered();
		}
		return res;
	}
}
//
//using namespace sf;
//Button::Button(sf::Texture* normal, sf::Texture* clicked, std::string words, sf::Vector2f location) {
//	this->normal.setTexture(*normal);
//	this->clicked.setTexture(*clicked);
//	this->currentSpr = &this->normal;
//	current = false;
//	this->normal.setPosition(location);
//	this->clicked.setPosition(location);
//	String.setString(words);
//	String.setPosition(location.x + 3, location.y + 3);
//	/*String.setSi(14);*/
//}
//void Button::checkClick(sf::Vector2f mousePos) {
//	/*if (mousePos.x > currentSpr->GetPosition().x && mousePos.x < (currentSpr->GetPosition().x + currentSpr->GetSize().x)) {
//		if (mousePos.y > currentSpr->GetPosition().y && mousePos.y < (currentSpr->GetPosition().y + currentSpr->GetSize().y)) {
//			setState(!current);
//		}
//	}*/
//}
//void Button::setState(bool which) {
//	current = which;
//	if (current) {
//		currentSpr = &clicked;
//		return;
//	}
//	currentSpr = &normal;
//}
//void Button::setText(std::string words) {
//	String.setString(words);
//}
//bool Button::getVar() {
//	return current;
//}
//sf::Sprite* Button::getSprite() {
//	return currentSpr;
//}
//
//
//
