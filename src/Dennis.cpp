#include "Dennis.h"



Dennis::Dennis(const sf::Vector2f& loc)
:Fighter(loc, Fighter_f::dennis_f), m_specialAction(0)
{}

void Dennis::doSth()
{

}


Fighter_f Dennis::whoAmI() const
{
    return Fighter_f::dennis_f;
}

//isKeyPressed