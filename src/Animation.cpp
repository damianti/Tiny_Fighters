#include <iostream>
#include "Animation.h"

auto transparentColor = sf::Color(1,1,1,0);


Animation::Animation(const AnimationData& data, sf::Sprite& sprite, Direction dir)
    :m_data(data), m_sprite(sprite), m_dir(dir)
{
    //m_sprite.setTexture(*ResourceManager::instance().getTexture2(Fighter_f::dennis_f));
    update(Action { ActionType::Standing, Direction::Right } ); //initial state

}

Animation::~Animation()
{
}


void Animation::direction(Direction dir)
{
    // if (m_dir == dir || dir == Direction::Stay)
    // {
    //     return;
    // }

    // m_dir = dir;
    // update();
}



// update for character
bool Animation::update (sf::Time delta, Action action)
{
    m_elapsed += delta;
    
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;

       
        // // case special attack completed a hit
        // if (action.first == ActionType::hit && m_index == m_animeMap.m_data.find(action.first)->second.size())
        //     return true;
        // burningFreezingCase(action);

        m_index %= m_data.m_data.find(action.first) ->second.size();
        update(action);
    }
    return false;
}

void Animation::update(Action action)
{
    if (action.first == ActionType::DieBack)
    {
        const static auto originalColor = m_sprite.getColor();

        fade ? m_sprite.setColor(transparentColor) : m_sprite.setColor(originalColor);
        fade = !fade;
        
    }

    m_sprite.setTextureRect(m_data.m_data.find(action.first)->second[m_index]);
    
    correctDir(m_sprite, action.second);
}
// void Animation::burningFreezingCase(Action action)
// {
//     // case character is burning or freezing
//     if ((action.first == ActionType::Freezing || action.first == ActionType::Burning || action.first == ActionType::Fading)
//         && m_index == m_animeMap.m_data.find(action.first)->second.size() - 1)
//     {
//         update(action);
//         m_index--;          //stay on the same frame
//     }
// }

// void Animation::setAnimationTime(const sf::Time& animationTime)
// {
//     m_animationTime = animationTime;
// }
