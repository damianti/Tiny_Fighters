#include "GameObject.h"

bool GameObject::collidWith(const GameObject& obj) const
{
	return (abs(y() - obj.y()) < 30.f) &&
		(abs(x() - obj.x()) < 80.f);
}

float GameObject::x() const
{
	return m_sprite.getPosition().x; 
}

float GameObject::y() const
{
	return m_sprite.getPosition().y; 
}