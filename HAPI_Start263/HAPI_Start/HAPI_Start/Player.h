#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	int movementSpeed{ 10 };
	// class call the playersprite stuff
public:
	Player::Player(int entityX, int entityY);
	void Update() override final;
	// void Render(GraphicsEngine& graphics);
	ESide GetSide() const override final { return ESide::ePlayer; }
};

