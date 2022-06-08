#pragma once
#include "macros.h"
#include "ResourceManager.h"

class GameBackground
{
public:
	GameBackground(const sf::Color& bgColor);
	virtual ~GameBackground() = default;
	
	/* Draw */
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void update(sf::Time delta) = 0;
	virtual sf::Vector2f getBackGroundSize();
protected:
	sf::RectangleShape m_ground;
};