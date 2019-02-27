#pragma once
#include "Widget.h"
#include"Layout.h"
namespace SoloStudios {

	class Container : public Widget
	{
	public:
		Container(Widget* parent = nullptr);
		virtual ~Container();

		void setLayout(Layout* layout);
		Layout* getLayout()const;

		virtual sf::Vector2f getSize()const override;

		virtual bool processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
		virtual void processEvents(const sf::Vector2f& parent_pos)override;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		

	private:
		Layout* _layout;
	};
}