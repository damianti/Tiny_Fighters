#pragma once
#include "macros.h"
#include "Utilities.h"
#include "ImageTexture.h"




class CharacterInfo
{
public:
    CharacterInfo (const int playerNum, const Fighter_f& fighter);

    void addHealth(const float);
    void addMana(const float);
    void draw(sf::RenderWindow& window) const;
    void update(const sf::Time& delta);
    void initializeShapes(std::pair <sf::RectangleShape , sf::RectangleShape>& rectangles, const bool manaOrHealth);
    void moveInfo(const int xPosition);

    int getHealth() const;
    int getMana() const;


private:
    std::pair <sf::RectangleShape, sf::RectangleShape> m_healthShape;
    float m_health;
    std::pair <sf::RectangleShape, sf::RectangleShape> m_manaShape;
    float m_mana;
    sf::Clock m_infoClock;
    const unsigned int m_playerNum;
    const Fighter_f m_fighter;
    std::shared_ptr <ImageTexture> m_icon;
};