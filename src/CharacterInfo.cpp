#include "CharacterInfo.h"


const std::unordered_map < Fighter_f , float > fighterLife =
{
    {   Fighter_f::dennis_f,   200.f   },
    {   Fighter_f::firzen_f,   200.f   },
    {   Fighter_f::louis_f,    200.f   },
    {   Fighter_f::bandit_f,   100.f   }
    
};

auto firstIconPosition = sf::Vector2(0.f,43.f);
auto firstInfoPosition = sf::Vector2(0.f,-30.f);
auto iconFactor = sf::Vector2(0.5f,0.5f);
auto infoWidth = 200.f;
auto infoHeight = 30.f;
auto infoSpace = 100.f;
auto yAxisOffset = 43.f;
auto shadowThickness = 2.f;
auto healthColor = sf::Color(190, 65, 65, 220);
auto healthBackColor = sf::Color(190, 65, 65, 100);
auto manaColor = sf::Color(39, 95, 245);
auto manaBackColor = sf::Color(39, 95, 245, 100);
const bool isHealth = false;
const bool isMana = true;


CharacterInfo::CharacterInfo (const int playerNum, const Fighter_f& fighter)
:m_health(infoWidth), m_mana(infoWidth), m_playerNum(playerNum), m_fighter(fighter)
{
    initializeShapes(m_healthShape, isHealth);
    initializeShapes(m_manaShape, isMana);
    m_icon = std::make_shared<ImageTexture>(sf::Vector2f{firstIconPosition.x + m_playerNum  * (infoWidth + infoSpace ) , firstIconPosition.y}, fighter, iconFactor);
}


void CharacterInfo::initializeShapes(std::pair <sf::RectangleShape , sf::RectangleShape>& rectangles, const bool manaOrHealth)
{
    sf::Color color = manaColor;
    sf::Color colorBack = manaBackColor;
    int offSet = yAxisOffset;
    if (manaOrHealth == isHealth) 
    {
        color = healthColor;
        colorBack = healthBackColor;
        offSet += infoHeight;
    }

    rectangles.first.setSize({infoWidth, infoHeight});
    rectangles.first.setFillColor(color);
    rectangles.first.setOutlineColor(color); //shdow
    rectangles.second.setOutlineThickness(shadowThickness); //shdow
    rectangles.first.setPosition({0 , firstInfoPosition.y + offSet + infoHeight * (m_playerNum / 4) });

    rectangles.second.setSize({infoWidth, infoHeight});
    rectangles.second.setFillColor(colorBack);
    rectangles.second.setPosition({0 , firstInfoPosition.y + offSet + infoHeight * (m_playerNum / 4) });
    rectangles.second.setOutlineColor(colorBack);
	rectangles.second.setOutlineThickness(shadowThickness); //shdow

}

void CharacterInfo::update(const sf::Time& delta)
{
    if (m_infoClock.getElapsedTime().asSeconds() > 0.5f)
    {
        m_mana +=  5;
        m_infoClock.restart();
    }

    if (m_health < 0)
        m_health = 0;

    else if (m_health > fighterLife.find(m_fighter)->second)
        m_health = fighterLife.find(m_fighter)->second;

    if (m_mana < 0)
        m_mana = 0;

    else if (m_mana> infoWidth)
        m_mana = infoWidth;

    if (!(abs(m_health - m_healthShape.first.getSize().x) < 1.f))
        m_healthShape.first.setSize({m_healthShape.first.getSize().x - delta.asMilliseconds() * 0.1f ,  m_healthShape.first.getSize().y });
    
    if (!(abs(m_mana - m_manaShape.first.getSize().x) < 1.f))
        m_manaShape.first.setSize({m_manaShape.first.getSize().x + sgn(m_mana - m_manaShape.first.getSize().x) * delta.asMilliseconds() * 0.1f ,  m_manaShape.first.getSize().y});
    
}


void CharacterInfo::draw(sf::RenderWindow& window) const
{   

    m_icon->draw(window);
    window.draw(m_healthShape.second);
    window.draw(m_healthShape.first);
    window.draw(m_manaShape.second);
    window.draw(m_manaShape.first);
    
}

void CharacterInfo::addHealth(const float power)
{
    m_health += power;
}

void CharacterInfo::addMana(const float power)
{
    m_mana += power;
}

int CharacterInfo::getHealth() const
{
    return m_health;
}

int CharacterInfo::getMana() const
{
    return m_mana;
}

void CharacterInfo::moveInfo(const int xPosition)
{
    m_icon->setPosition({xPosition + m_playerNum  * (infoWidth + infoSpace ) + infoWidth/ 1.2f , m_icon->getPosition().y});
    m_healthShape.first.setPosition({xPosition + (m_playerNum%4)   * (infoWidth + infoSpace ) + infoWidth , m_healthShape.first.getPosition().y});
    m_healthShape.second.setPosition({xPosition + (m_playerNum % 4) * (infoWidth + infoSpace ) + infoWidth, m_healthShape.second.getPosition().y});
    
    m_manaShape.first.setPosition({xPosition + (m_playerNum % 4) * (infoWidth + infoSpace ) + infoWidth, m_manaShape.first.getPosition().y});
    m_manaShape.second.setPosition({xPosition + (m_playerNum % 4) * (infoWidth + infoSpace ) + infoWidth , m_manaShape.second.getPosition().y});
}