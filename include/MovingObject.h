#pragma once
#include "macros.h"
#include "Animation.h"
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject();
	MovingObject(const sf::Vector2f& CenterPos, const Bg_sp_t& objectTex, const sf::Vector2f& factor);
	MovingObject( const sf::Vector2f& CenterPos, const Fighter_f& objectTex, const sf::Vector2f& factor);
	MovingObject(const sf::Vector2f& CenterPos, const Dynamic_t& objectTex, const sf::Vector2f& factor);
	void move(const sf::Time& deltaTime);
	virtual void update(const sf::Time& deltaTime);

	/* Mutator */
	void setDirection(sf::Keyboard::Key key);
	void setAction(const Action& action);
	void setActionType(const ActionType& action);
	//void direction(const sf::Vector2f& dir);
	virtual bool isInsideBoard() const;

	void direction(const Direction dir);
	void setDelay(const bool delay);

	/* Accesors */
	sf::Vector2f getDirection() const;
	ActionType getAction() const ;

protected:
	sf::Vector2f m_direction;
    Direction m_dir = Direction::Stay;
	Animation m_animation;
	Action m_action;
	float m_speed;
	sf::Clock m_delayClock;
	sf::Clock m_moveClock;
	float m_delayTime;
	bool m_isDelayed;
};