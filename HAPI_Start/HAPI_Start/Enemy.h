#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:

public:
	Enemy::Enemy(int entityX, int entityY, float health);
	void Update() override final;
	// allows the compiler to warn you if you have made 
	// a spelling mistake

	ESide GetSide() const override final { return ESide::eEnemy; }

};

