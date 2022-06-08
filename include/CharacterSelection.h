#pragma once

#include "macros.h"
#include "State.h"
//#include "Player.h"
#include "ImageTexture.h"
#include "ImageText.h"
#include "Utilities.h"



class CharacterSelection : public State
{
public:
	CharacterSelection(sf::RenderWindow& window, int numOfPlayers = 1);

	/* draw */
	void draw() override;
	std::vector <playerData> choose();
	void handleView() override {};
	void handleClick(const sf::Vector2f& ) override {}
	void handleKeyPress(sf::Keyboard::Key key) override;
	void handleKeyPress() override {}
	void handleKeyReleased(sf::Keyboard::Key ) override {}
	void handleMove(const sf::Vector2f& ) override {}
private:
	struct PlayerDataMap
	{
		std::pair<std::shared_ptr<Image>, CommandType> m_commanderType;
		std::pair<std::shared_ptr<Image>, Fighter_f> m_fighter;
		std::pair<std::shared_ptr<Image>, unsigned int >playerNum;
		std::pair<std::shared_ptr<Image>, Team >team;
	};
	std::vector<PlayerDataMap >m_playerData;
	ActiveSelectType m_ElemChoosePtr;
	std::vector<PlayerDataMap>::iterator m_PlayerIter;
	int m_numOfPlayers;
	/* Private Functions */
	void createButton(int numOfPlayers);
	sf::Vector2f getImagePlayerPostion(const selectType index, int i);
	void handleSidesKey(int move);
};

