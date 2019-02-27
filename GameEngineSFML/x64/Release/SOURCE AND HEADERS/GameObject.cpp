#include "GameObject.h"


namespace SoloStudios {


	/*GameObject::GameObject()
	{

		
	}*/
/*
	void GameObject::setTexture(Texture texture)
	{
		_sprite.setTexture(texture);
	}*/

	void GameObject::setVelocity(Vector2f vel)
	{
		_velocity = vel;
	}

	Vector2f GameObject::getVelocity() const
	{
		return _velocity;
	}
}
