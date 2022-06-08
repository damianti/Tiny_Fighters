#pragma once

#include "macros.h"
#include "Player.h"

class ArenaSelection
{
public:
	ArenaSelection::ArenaSelection(sf::RendewWindow& window);
	run(sf::RendewWindow& window);
	void pollEvents(sf::RenderWindow& window);
private:
	struct data
	{
		std::vector <Arena_t> m_background;
		std::vector <Player_t> m_players;
	}

	/* Private Functions */
	choosePlayers();
};