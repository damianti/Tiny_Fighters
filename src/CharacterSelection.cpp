#include "CharacterSelection.h"

CharacterSelection::CharacterSelection(sf::RenderWindow& window, int numOfPlayers)
    :State(window, Type_t::bg_manu), m_numOfPlayers(numOfPlayers)
{
    createButton(numOfPlayers);
}

sf::Vector2f CharacterSelection::getImagePlayerPostion(const selectType type, int i)
{
    switch (type)
    {
    case selectType::Commander:
        return sf::Vector2f(Select_User_Image_Start_Pos.x + (i % 4) * Select_User_Image_Space.x,
            Select_User_Image_Start_Pos.y + (i / 4) * Select_User_Image_Space.y);
    case selectType::fighter:
        return sf::Vector2f(Select_Fighter_Image_Start_Pos.x + (i % 4) * Select_Fighter_Image_Space.x,
            Select_Fighter_Image_Start_Pos.y + (i / 4) * Select_Fighter_Image_Space.y);
    case selectType::num:
        return sf::Vector2f(Select_playerNum_Image_Start_Pos.x + (i % 4) * Select_playerNum_Image_Space.x,
            Select_playerNum_Image_Start_Pos.y + (i / 4) * Select_playerNum_Image_Space.y);
    case selectType::team:
        return sf::Vector2f(Select_team_Image_Start_Pos.x + (i % 4) * Select_team_Image_space_Pos.x,
            Select_team_Image_Start_Pos.y + (i / 4) * Select_team_Image_space_Pos.y);
    default: return sf::Vector2f(0, 0);
    }

}

std::vector <playerData> CharacterSelection::choose()
{
    m_PlayerIter = m_playerData.begin();
    m_ElemChoosePtr = ActiveSelectType::fighter;
    run();
    std::vector <playerData> loadChoosed;

    for (auto& player : m_playerData)
    {
        loadChoosed.push_back(playerData{
                player.m_commanderType.second,
                player.m_fighter.second,
                player.playerNum.second,
                player.team.second
            }
        );
    }
    return loadChoosed;
}
void CharacterSelection::draw()
{
    /* Draw Menu */
    for (auto& player : m_playerData)
    {
        player.m_commanderType.first->draw(m_window);
        player.m_fighter.first->draw(m_window);
        player.playerNum.first->draw(m_window);
        player.team.first->draw(m_window);
    }
}

void CharacterSelection::handleKeyPress(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Left: handleSidesKey(-1); break;
    case sf::Keyboard::Right:handleSidesKey(1); break;
    case sf::Keyboard::Enter:
    {

        m_ElemChoosePtr = ActiveSelectType(int(m_ElemChoosePtr) + 1) ;
        if (m_ElemChoosePtr == ActiveSelectType::end) { m_ElemChoosePtr = ActiveSelectType::fighter; m_PlayerIter++; }
        if (m_PlayerIter == m_playerData.end()) m_isRunning = false;
    }
    break;
    case sf::Keyboard::RShift:
    {
        m_ElemChoosePtr = ActiveSelectType(int(m_ElemChoosePtr) - 1);
        if (m_ElemChoosePtr == ActiveSelectType::start) { m_ElemChoosePtr = ActiveSelectType::fighter; m_PlayerIter--; }
        if (m_PlayerIter == m_playerData.begin()) m_PlayerIter = m_playerData.begin();
    }
    break;
    default:
        break;
    }
}

void CharacterSelection::handleSidesKey(int move)
{
  

    switch (m_ElemChoosePtr)
    {
    case ActiveSelectType::fighter:
    {
        auto next = (int(m_PlayerIter->m_fighter.second) + move) % numOfFighters;
        if (auto texture = dynamic_cast<ImageTexture*>(m_PlayerIter->m_fighter.first.get()))
        {
            texture->setTexture(Fighter_f(next));
            m_PlayerIter->m_fighter.second = Fighter_f(next);
        }
        break;
    }
    case ActiveSelectType::team:
    {
        auto nextTeam = (int(m_PlayerIter->team.second) + move) % maxOfTeams;
        {
            if (auto string = dynamic_cast<ImageText*>(m_PlayerIter->team.first.get()))
                string->setString(teamStrings[nextTeam]);
            m_PlayerIter->team.second = Team(nextTeam);
        }
        break;
    }
    }
}


void  CharacterSelection::createButton(int numOfPlayers)
{
    for (int i = 0; i < numOfPlayers; i++)
        m_playerData.emplace_back(PlayerDataMap
            {
                {
                    std::make_pair(std::make_shared <ImageText>(userString[(int)CommandType::Computer], getImagePlayerPostion(selectType::Commander, i)), CommandType::Computer)
                },
                {
                    std::make_pair(std::make_shared <ImageTexture>(getImagePlayerPostion(selectType::fighter, i), Fighter_f::dennis_f, Select_Factor), Fighter_f::dennis_f)
                },
                {
                    std::make_pair(std::make_shared <ImageText>(std::to_string(i), getImagePlayerPostion(selectType::num, i)),  i)
                },
                {
                    std::make_pair(std::make_shared <ImageText>(teamStrings[(int)Team::Team_A], getImagePlayerPostion(selectType::team, i)), Team::Team_A)
                }
            }); 
    //init first player as user
    if (auto texture = dynamic_cast<ImageText*>(m_playerData.begin()->m_commanderType.first.get()))
        texture->setString(userString[(int)CommandType::ArrowUser]);
    m_playerData.begin()->m_commanderType.second = CommandType::ArrowUser;
    

}

