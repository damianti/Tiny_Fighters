#include "DennisBall.h"

DennisBall::DennisBall(const Direction& dir, const sf::Vector2f& startPos, const playerData ownerNum)
	:DynamicAttack(dir, startPos, Dynamic_t::dennisBall_t, dennisBallDmg, ownerNum),m_dir(dir)
{
	m_speed = dennisBallSpeed;
	MovingObject::setAction({ ActionType::CreateBall, Direction::Stay });
	setDelay(true);
}

void DennisBall::update(const sf::Time& delta)
{
	if (m_delayClock.getElapsedTime().asSeconds() > m_delayTime)
		setDelay(false);

	if (getAction() == ActionType::ExplodeBall && !m_isDelayed)
		m_isDone = true;
	
	if(!m_isDelayed && getAction() != ActionType::ExplodeBall)	
		MovingObject::setAction({ ActionType::ShotBall, m_dir });

	if (!DennisBall::isInsideBoard() && getAction() != ActionType::ExplodeBall)
	{
		MovingObject::setAction({ ActionType::ExplodeBall, Direction::Stay });
		setDelay(true);
	}
	
	
	MovingObject::update(delta);
}


bool DennisBall::isInsideBoard() const
{
	auto& pos = m_sprite.getPosition();
	auto size = m_sprite.getTexture()->getSize();
	auto spriteBotleft = sf::Vector2(pos.x - size.x / 2 + 350, pos.y + size.y / 2 - 150);
	auto spriteBotright = sf::Vector2(pos.x + size.x / 2 - 350, pos.y + size.y / 2 - 150);
	return GroundRect.contains(spriteBotleft) && GroundRect.contains(spriteBotright);
}
