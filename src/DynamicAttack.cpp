#include"DynamicAttack.h"

DynamicAttack::DynamicAttack(const Direction& dir, const sf::Vector2f& startPos, const Dynamic_t ObjType, const float dmg, const playerData ownerNum)
	:MovingObject(startPos, ObjType, ballFactor)
	,m_dir(dir), m_startPos(startPos), m_isDone(false), m_dmg(dmg), m_owner(ownerNum)
{
}

playerData DynamicAttack::getOwner()
{
	return m_owner;
}

float DynamicAttack::getDmg()
{
	return m_dmg;
}

bool DynamicAttack::isDone()
{
	return m_isDone;
}
