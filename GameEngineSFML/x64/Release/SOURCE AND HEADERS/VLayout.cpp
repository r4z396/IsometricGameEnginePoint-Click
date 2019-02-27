
#include "VLayout.h"


namespace SoloStudios {
	VLayout::VLayout(Widget* parent) : Layout(parent)
	{
	}

	VLayout::~VLayout()
	{
		for (Widget* widget : _widgets)
		{
			if (widget->_parent == this)
				delete widget;
		}
	}

	void VLayout::add(Widget* widget)
	{
		widget->_parent = this;
		_widgets.emplace_back(widget);
		updateShape();
	}

	Widget* VLayout::at(unsigned int index)const
	{
		return _widgets.at(index);
	}

	sf::Vector2f VLayout::getSize()const
	{
		float max_x = 0;
		float y = 0;
		for (Widget* widget : _widgets)
		{
			sf::Vector2f size = widget->getSize();
			if (size.x > max_x)
				max_x = size.x;
			y += _space + size.y;
		}
		return sf::Vector2f(max_x + _space * 2, y + _space);
	}

	bool VLayout::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		for (Widget* widget : _widgets)
		{
			if (widget->processEvent(event, parent_pos))
				return true;
		}

		return false;
	}

	void VLayout::processEvents(const sf::Vector2f& parent_pos)
	{
		for (Widget* widget : _widgets)
			widget->processEvents(parent_pos);
	}

	void VLayout::updateShape()
	{
		float max_x = (_parent ? _parent->getSize().x : 0);
		
		std::cout << std::endl<<"-----------------------------------";
		std::cout << std::endl << "MAX SPACE";
		std::cout << std::endl<<max_x;
		std::cout << std::endl << "-----------------------------------";
		for (Widget* widget : _widgets)
		{
			sf::Vector2f size = widget->getSize();
			float widget_x = size.x;
			std::cout << std::endl << "-----------------------------------";
			std::cout << std::endl << "SIZE WIDGET";
			std::cout << std::endl << widget_x;
			std::cout << std::endl << "-----------------------------------";
			if (widget_x > max_x)
				max_x = widget_x;
		}

		float pos_y = _space;
		std::cout << std::endl << "-----------------------------------";
		std::cout << std::endl << "SPACE LAYOUT";
		std::cout << std::endl << _space;
		std::cout << std::endl << "-----------------------------------";
		if (_parent) {
			pos_y = (_parent->getSize().y - getSize().y) / 2.f;
			std::cout << std::endl << "-----------------------------------";
			std::cout << std::endl << "POS DEL LAYOUT";
			std::cout << std::endl << pos_y;
			std::cout << std::endl << "-----------------------------------";
		}
			

		for (Widget* widget : _widgets)
		{
			sf::Vector2f size = widget->getSize();
			if (_parent) {
				std::cout << std::endl << "POSITIONNNNNNN PARENT" << "  " << _parent->getPosition().x;
				widget->setPosition((((max_x - size.x) / 2.0) + _parent->getPosition().x), (pos_y + _parent->getPosition().y));
			}
			else {
				widget->setPosition((((max_x - size.x) / 2.0) ), (pos_y ));
			}
			pos_y += size.y + _space;
			std::cout << std::endl << "-----------------------------------";
			std::cout << std::endl << "POS DEL WIDGET";
			std::cout << std::endl << pos_y;
			std::cout << std::endl << "-----------------------------------";
		}

		Widget::updateShape();

		std::cout << "updated shapeee";

	}

	void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (Widget* widget : _widgets)
			target.draw(*widget, states);
	}
}
