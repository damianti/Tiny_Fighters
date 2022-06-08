#include "MovingObject.h"


// MovingObject::MovingObject( const sf::Vector2f& pos, const Fighter_f objectTex)
// 	:GameObject(pos, objectTex)
// {}
MovingObject::MovingObject( const sf::Vector2f& CenterPos, const Fighter_f& fighter, const sf::Vector2f& factor)

    : GameObject(CenterPos, factor ),
		m_animation(ResourceManager::instance().animationData(fighter), m_sprite, Direction::Right),
		m_action(ActionType::Standing, Direction::Stay),
		m_isDelayed(false)
{

	m_sprite.setTexture(*ResourceManager::instance().getTexture2(fighter));
		// for correct rotation, setting origin at center
	m_sprite.setOrigin(m_sprite.getLocalBounds().height / 2,
						m_sprite.getLocalBounds().width / 2);


}

MovingObject::MovingObject(const sf::Vector2f& CenterPos, const Bg_sp_t& objectTex, const sf::Vector2f& factor)
	: GameObject(CenterPos, factor),
	m_animation(ResourceManager::instance().animationData(Bg_sp_t::fire), m_sprite, Direction::Right),
	m_action(ActionType::Standing, Direction::Stay), m_isDelayed(false)
{

	m_sprite.setTexture(*ResourceManager::instance().getTexture(objectTex));
	// for correct rotation, setting origin at center
	m_sprite.setOrigin(m_sprite.getLocalBounds().height / 2,
		m_sprite.getLocalBounds().width / 2); 
}

MovingObject::MovingObject(const sf::Vector2f& CenterPos, const Dynamic_t& objectTex, const sf::Vector2f& factor)
	: GameObject(CenterPos, factor),
	m_animation(ResourceManager::instance().animationData(Dynamic_t::dennisBall_t), m_sprite, Direction::Right),
	m_action(ActionType::Standing, Direction::Stay), m_isDelayed(false)
{

	m_sprite.setTexture(*ResourceManager::instance().getTexture(objectTex));
	// for correct rotation, setting origin at center
	m_sprite.setOrigin(m_sprite.getLocalBounds().height / 2,
		m_sprite.getLocalBounds().width / 2);
}

void MovingObject::move(const sf::Time& deltaTime)
{
	m_sprite.move(toVector(m_action.second) * deltaTime.asSeconds() * m_speed);
	if(!MovingObject::isInsideBoard())
		m_sprite.move(OpposideVector(m_action.second) * deltaTime.asSeconds() * m_speed);
}

bool MovingObject::isInsideBoard() const
{
	auto &pos = m_sprite.getPosition();
	auto size = m_sprite.getTexture()->getSize();
	auto spriteBotleft = sf::Vector2(pos.x - size.x / 2 + 270, pos.y + size.y / 2 - 150);
	auto spriteBotright = sf::Vector2(pos.x + size.x / 2 - 270, pos.y + size.y / 2 - 150);
	return GroundRect.contains(spriteBotleft) && GroundRect.contains(spriteBotright);

}
void MovingObject::update(const sf::Time& deltaTime)
{
	
	m_animation.update(deltaTime, m_action);
}


void  MovingObject::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0); break;
	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0); break;
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1); break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1); break;
	default://reset direction
		m_direction = sf::Vector2f(0, 0); break;
	}
}

void MovingObject::setAction(const Action& action)
{
	m_action = action;
}

void MovingObject::setActionType(const ActionType& action)
{
	m_action.first = action;
}

sf::Vector2f MovingObject::getDirection() const
{
	return m_direction;
}

ActionType MovingObject::getAction() const 
{
	return m_action.first;
}

void MovingObject::direction(const Direction dir)
{
	m_dir = dir;
	m_animation.direction(dir);
}

void MovingObject::setDelay(const bool delay)
{
	auto actionDelay = delayOfAction.find(m_action.first);
	if (actionDelay != delayOfAction.end())
	{
		m_delayClock.restart();
		m_delayTime = actionDelay->second;
		m_isDelayed = delay;
	}

}