#include "UserCommander.h"

UserCommander::UserCommander( const playerData& playerData)
    :Commander(playerData)
{}


std::pair< std::vector<ActionType>, std::vector<Direction> > UserCommander::getAction() const 
{
    std::pair < std::vector <ActionType >, std::vector <Direction> > actionTypesAndDirections;
    std::vector <ActionType> actionTypePressed;
    std::vector <Direction> directionPressed;
    
    for (auto& pair : mapKeyboardToActionType[(int)m_playerData.m_commander])
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
            actionTypesAndDirections.first.push_back(pair.second);
    }

    for (auto& pair : mapKeyboardToDir[(int)m_playerData.m_commander])
    {
        if (sf::Keyboard::isKeyPressed(pair.first))
            actionTypesAndDirections.second.push_back(pair.second);
    }
    return actionTypesAndDirections;
}

void UserCommander::getActionFromKeyReleased(const sf::Keyboard::Key& keyReleased)
{
    if (m_possibleCombo.empty())
        m_comboClock.restart();
    
    if ((m_comboClock.getElapsedTime().asSeconds() < 0.5f))
    {
        m_possibleCombo.push_back(keyReleased);
        m_comboClock.restart();
    }
    


    if (auto combo = searchCombo())
        m_combo = combo->first;
    
    else  m_combo = ActionType::Standing; //there is no combo in keyboard
}


std::optional<Action> UserCommander::searchCombo() //auto vecOfPAirs = {{}}
{
    auto possibleCombo = std::find_if(comboData[int(m_playerData.m_fighter)].begin(),
                                        comboData[int(m_playerData.m_fighter)].end(),
                                [this](auto pair){return pair.first == this->m_possibleCombo;});

    if (possibleCombo != comboData[int(m_playerData.m_fighter)].end())
        return possibleCombo->second;

    return {};
}

void UserCommander::update()
{
    if (m_comboClock.getElapsedTime().asSeconds() > 0.5f)
    {
        m_possibleCombo.clear();
        m_combo = ActionType::Standing;
    }
}