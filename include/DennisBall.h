#pragma once
#include "macros.h"
#include "DynamicAttack.h"

class  DennisBall : public DynamicAttack
{
public:
	DennisBall(const Direction& dir, const sf::Vector2f& startPos, const playerData ownerNum);
	bool isInsideBoard() const override;

	/* Accesors */
	void update(const sf::Time& delta) override;

	/* Mutator */
private:
	Direction m_dir;

};