#pragma once
#include "macros.h"
#include "Fighter.h"

class Firzen : public Fighter
{
public:
	Firzen(const sf::Vector2f& loc);
	Fighter_f whoAmI() const;
	void doSth();
private:
	//Action m_specialAction;
};