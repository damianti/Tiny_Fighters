#pragma once
#include "macros.h"
#include "DynamicAttack.h"

class  FirzenBall : public DynamicAttack
{
public:
	FirzenBall(const Direction& dir, const sf::Vector2f& startPos, const playerData ownerNum);
	bool isInsideBoard() const override;

	/* Accesors */
	void update(const sf::Time& delta) override;

	/* Mutator */
private:
	Direction m_dir;

};