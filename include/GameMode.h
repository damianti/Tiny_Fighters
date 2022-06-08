#pragma once

#include "macros.h"
#include "State.h"
#include "CharacterSelection.h"
#include "Fighter.h"
#include "DennisBall.h"
#include "Collision.h"
#include "SPBackground.h"
#include "CWBackground.h"


class GameMode: public State
{
public:
	GameMode(sf::RenderWindow& window);
	void update() override;
	void draw() override;
	void handleView() override;

	void handleMove(const sf::Vector2f& ) override {}
	void pollEvents() override;
	void setAction();
	void manageComputerAlgorithm();
	void getDynamicAttacks();

protected:

	void handleCollison();
	void moveAndAnimation(const sf::Time& delta);
	void handleKeyPress(sf::Keyboard::Key ) override {}
	void handleKeyPress() override {}
	void handleKeyReleased(sf::Keyboard::Key key) override;
	void handleClick(const sf::Vector2f& ) override {}
 	void createPlayers(std::vector < playerData > players);
	virtual sf::Vector2f getStartPos(const int character) const ;
	std::shared_ptr <Fighter> minimumDistanceFighterTo(const std::shared_ptr <Fighter> fighter);
	//CharacterSelection m_selection;
	using Players = std::vector<std::shared_ptr<Fighter>>;
	using DynamicAttacks = std::vector<std::shared_ptr<DynamicAttack>>;
	Players m_characters;
	DynamicAttacks m_dynamicAttack;

	//Arena Background m_background;
	std::unique_ptr<GameBackground> m_background;


	sf::Clock m_tempClock;
	/* Protected Functions */
	void selection();
};