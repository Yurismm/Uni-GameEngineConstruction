#pragma once
#include "Entity.h"


class BackgroundEntity : public Entity
{
private:
public:
	BackgroundEntity::BackgroundEntity(int entityX, int entityY);
	void Update() override final;
	ESide GetSide() const override final { return ESide::eNeutral; }
};

