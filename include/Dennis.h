#pragma once
#include "macros.h"
#include "Fighter.h"

class Dennis : public Fighter
{
public:
	Dennis(const sf::Vector2f& loc);
	Fighter_f whoAmI() const ;
	void doSth();
private:
	
	int m_specialAction;
};