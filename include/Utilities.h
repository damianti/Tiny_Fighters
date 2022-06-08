#pragma once
#include"macros.h"
#include"GameObject.h"


template <typename T1, typename T2>
struct ButtonDetails
{
	std::shared_ptr<T1> m_button;
	T2 type;
};

template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
    for (; begin != end; ++begin)
        for (auto second = begin + 1; second != end; ++second)
            fn(*begin, *second);
}
bool collide(GameObject& a, GameObject& b);
void correctDir(sf::Sprite&, Direction);
sf::Vector2f toVector(Direction dir = Direction::Stay);
Direction toDir (const sf::Vector2f victor);
Direction oppositeDir(Direction dir);
sf::Vector2f OpposideVector(Direction dir);
float calcDistance(const sf::Vector2f& v1, const sf::Vector2f& v2);
Direction TextureFacing(sf::Sprite& pic);
// #pragma once
// #include "macros.h"
// #include "ResourcesManager.h"
// #include <vector>
// #include <string>

// class Character;
// class Arena;

// // struct to substitute sf::Sound in order to simplify the code and set buffer a single time
// struct Effect
// {
// 	Effect() {}
// 	Effect(int type)
// 	{
// 		m_data.setBuffer(ResourcesManager::instance().getSound(type));
// 		m_data.setVolume(VOLUME);
// 	}
// 	sf::Sound m_data;

// 	void setSound(AttackType type)
// 	{
// 		m_data.setBuffer(ResourcesManager::instance().getSound((int)type));
// 		m_data.setVolume(VOLUME);
// 	}

// 	void play() { m_data.play(); }
// 	sf::SoundSource::Status getStatus() { return m_data.getStatus(); }
// };

// bool outOfBounds(const sf::Vector2f&);
// void correctDir(sf::Sprite&, Direction);
// void twoCharactersCollision(Character&, Character&);