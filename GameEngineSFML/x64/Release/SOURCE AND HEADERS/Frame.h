#pragma once

#include "Container.h"
#include "ActionTarget.hpp"
#include "Config.h"


namespace SoloStudios {
	class Frame : public Container, protected ActionTarget<int>
	{
	public:
		using ActionTarget<int>::FuncType;
		Frame(sf::RenderWindow& window);
		virtual ~Frame();

		void processEvents();
		bool processEvent(const sf::Event& event);

		void bind(int key, const FuncType& callback);
		void unbind(int key);

		void draw();
		virtual sf::Vector2f getSize()const override;
		void setSize(sf::Vector2f _size);
		void setPos(sf::Vector2f _pos);
		sf::Vector2f pos;
		sf::Vector2f size;


	private:
		sf::RenderWindow& _window;
		sf::RectangleShape _shape;
		
		virtual bool processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
		virtual void processEvents(const sf::Vector2f& parent_pos)override;
	};
}


