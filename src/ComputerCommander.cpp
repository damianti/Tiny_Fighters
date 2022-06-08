#include "ComputerCommander.h"

const float smallDistance = 8.f;


ComputerCommander::ComputerCommander(const playerData& playerData)
    :Commander(playerData), m_lastAction(Action{ActionType::Walking, Direction::Right})
{}



Action ComputerCommander::getActionFromAlgo(const sf::Vector2f& myPos, const sf::Vector2f& targetPos)
{
    if (abs(myPos.x - targetPos.x) < 35.f)
        return {Action {ActionType::Punching, Direction::Stay}};

    else
        return Action {ActionType::Walking, toDir(sf::Vector2f {(float) sgn (targetPos.x - myPos.x), 
                                                        (float)  sgn (targetPos.y - myPos.y)})};
}

Action ComputerCommander::setRandomAction()
{
    if (m_commmanderClock.getElapsedTime().asSeconds() > 1.f)
    {
        m_commmanderClock.restart();
        m_lastAction = Action {ActionType::Walking, randomMapDirection.find(rand() % 7)->second};
    }

    return m_lastAction;

}


void ComputerCommander::update()
{}
