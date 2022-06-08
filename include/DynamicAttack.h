#pragma once
#include "macros.h"
#include "MovingObject.h"

class DynamicAttack : public MovingObject
{
public:
	DynamicAttack(const Direction& dir, const sf::Vector2f& startPos, const Dynamic_t ObjType, const float dmg, const playerData owner);

	/* Accesors */
	virtual void update(const sf::Time& delta) = 0;
	playerData getOwner ();
	float getDmg ();
	bool isDone();
	/* Mutator */
protected:
	Direction m_dir;
	sf::Vector2f m_startPos;
	bool m_isDone;
	sf::Clock m_ClockTime;
	float m_dmg;
	playerData m_owner;
};