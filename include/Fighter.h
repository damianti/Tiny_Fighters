#pragma once
#include "macros.h"
#include "UserCommander.h"
#include "ComputerCommander.h"
#include "MovingObject.h"
#include "CharacterInfo.h"
#include "DennisBall.h"
#include "FirzenBall.h"

class Fighter : public MovingObject
{
public:
	Fighter(const playerData& PlayerData, const sf::Vector2f& pos);
	Fighter(const sf::Vector2f& pos);
	//virtual Fighter_f whoAmI() const = 0;

	/* Draw */
	void draw(sf::RenderWindow& window) const override;

	/* Mutator */
	void update(const sf::Time& delta) override;
	void startCommander(const playerData& playerData);
	void setAction();
	void setAction(const std::vector<Action>& actionsPressed);

	Direction setDir(const std::vector <Direction>& directionsPressed) const;
	void setCombo(const ActionType combo);
	void setTarget(const std::shared_ptr <Fighter> fighter) ;

	ActionType setActionTypeFromKeyboard(std::vector <ActionType>& actionsPressed, const Direction& dir) const;
	void setInfoView(const float xPosition);
	void addHealth(const float health);
	void decHealth(const float health);

	/* Accesors */
	playerData getPlayerData() const;
	bool isDelayed() const;
	bool isDead() const;
	bool isGoingToDie() const;
	
	void getActionFromKeyReleased(const sf::Keyboard::Key& keyReleased);
	std::shared_ptr <DynamicAttack> getDynamicAttacks();
protected:

	playerData m_playerData;
	ActionType m_combo;
	std::shared_ptr <Commander> m_commander;
	std::shared_ptr <CharacterInfo> m_info;
	std::shared_ptr <DynamicAttack> m_dynamicAttack;
	std::shared_ptr <Fighter> m_target;
	bool m_isDead;
	const float m_fighterSpeed;
	void setSpeed();
	
	void deathProcess();
	void activateCombo();
};