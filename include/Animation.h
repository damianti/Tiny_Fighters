#pragma once
#include "AnimationData.h"
#include "ResourceManager.h"
#include "macros.h"
#include "Utilities.h"

class Animation
{
public:
	Animation(const AnimationData&, sf::Sprite&, Direction dir);
	~Animation();

	bool update(sf::Time, Action); //returns true if finished animation
	void setAnimationTime(const sf::Time&);
	void direction(Direction dir);

private:
	void update(Action action);			
	//void burningFreezingCase(Action);	//special case for burning and freezing

	const AnimationData& m_data;
	sf::Time m_elapsed = {};
	//sf::Time m_animationTime;
	Direction m_dir = Direction::Up;
	int m_index = 0;			//index in AnimationData
	sf::Sprite& m_sprite;		//The sprite of the gameObject
	bool fade;
};
