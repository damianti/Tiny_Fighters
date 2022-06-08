#pragma once
#include "macros.h"
#include "Background.h"

class Stage
{
public:
	Stage();
private:
	sf::RectangleShape m_floor;
	Background m_background;
};