#include "Frame.h"


namespace SoloStudios {
	Frame::Frame(sf::RenderWindow& window) : Container(nullptr), ActionTarget(Config::guiInputs), _window(window) {
		_shape.setFillColor(sf::Color(40, 20, 50));
	}
	Frame::~Frame() {}

	void Frame::draw() { 
		_window.draw(_shape);
		_window.draw(*this);		
		
	}

	void Frame::bind(int key, const FuncType& callback) { ActionTarget::bind(key, callback); }

	void Frame::unbind(int key) { ActionTarget::unbind(key); }
	void Frame::setSize(sf::Vector2f _size) {
		size = _size;
		_shape.setSize(size);
	}
	void Frame::setPos(sf::Vector2f _pos) {
		pos = _pos;
		this->setPosition(pos);
		_shape.setPosition(pos);
	}
	sf::Vector2f Frame::getSize()const
	{
		//sf::Vector2u size = _window.getSize();
		std::cout << "nfjksbfklsdbfkjlsbfkjosb ekjlf snklfbelshif jks";
		return this->size;
		//return sf::Vector2f(size.x, size.y);
	}

	void Frame::processEvents()
	{
		sf::Vector2f parent_pos(0, 0);
		processEvents(parent_pos);
	}
	bool Frame::processEvent(const sf::Event& event)
	{
		sf::Vector2f parent_pos(0, 0);
		return processEvent(event, parent_pos);
	}

	bool Frame::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
	{
		bool res = ActionTarget::processEvent(event);
		
		if (not res)

		bool res;
			res = Container::processEvent(event, parent_pos);
		return res;
		
	}

	void Frame::processEvents(const sf::Vector2f& parent_pos)
	{
		ActionTarget::processEvents();
		Container::processEvents(parent_pos);
		sf::Event event;
		while (_window.pollEvent(event))
			Container::processEvent(event, parent_pos);
	}
}