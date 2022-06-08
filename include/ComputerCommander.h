#pragma once

#include "macros.h"
#include "Utilities.h"
#include "Commander.h"

class ComputerCommander : public Commander
{
public:
    ComputerCommander(const playerData& playerData);
    
    Action getActionFromAlgo(const sf::Vector2f& myPos, const sf::Vector2f& targetPos) override;
    Action setRandomAction() override;
    void update() override;

private:
    
    sf::Clock m_commmanderClock;
    Action m_lastAction;
};