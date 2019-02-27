#pragma once
#ifndef WIDGET_H
#define WIDGET_H
#include "SFML/Graphics.hpp"
#include <iostream>
namespace SoloStudios {


	class Widget : public sf::Drawable
	{
	public:
		Widget(Widget* parent = nullptr);
		virtual ~Widget();

		void setPosition(const sf::Vector2f& pos);
		void setPosition(float x, float y);
		const sf::Vector2f& getPosition()const;
		virtual sf::Vector2f getSize()const = 0;
		Widget* _parent;
		sf::Vector2f _position;

		virtual bool processEvent(const sf::Event& event, const sf::Vector2f& parent_pos);
		virtual void processEvents(const sf::Vector2f& parent_pos);
		virtual void updateShape();
	protected:
		

		
	};
}
#endif