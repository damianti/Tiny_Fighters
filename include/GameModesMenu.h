#pragma once
#include "State.h"


class GameModesMenu : State
{
public:
	GameModesMenu();

private:
	std::unique_ptr<GameMode> m_mode;
	std::vector<MenuButtons> m_Buttons;
	

	//Menu functions
	void handleClick(const sf::Vector2f& location, sf::RenderWindow& window);
	void initMenu();
	void initButtons();
};