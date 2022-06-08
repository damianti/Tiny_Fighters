#include "Firzen.h"




Firzen::Firzen(const sf::Vector2f& loc)
:Fighter(loc, Fighter_f::firzen_f)
{}

void Firzen::doSth()
{

}


Fighter_f Firzen::whoAmI() const
{
    return Fighter_f::firzen_f;
}

//isKeyPressed