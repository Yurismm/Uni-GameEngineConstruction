#include "Entity.h"
#include "GraphicsEngine.h"

void Entity::Render(GraphicsEngine& graphics, float s)
{
	// interpolated values
	float interpX = OLDe_x + (e_x - OLDe_x) * s;
	float interpY = OLDe_y + (e_y - OLDe_y) * s;

	graphics.DrawSprite(spriteName, e_x, e_y);
}

bool Entity::IsEnemyOf(Entity* other) const
{
	if (GetSide() == ESide::eNeutral)
		return false;

	if (other->GetSide() == ESide::eNeutral)
		return false;
	
	if (other->GetSide() == GetSide())
		return false;

	return true;

}

bool Entity::CheckCollisionAgainst(Entity* other) const
{
	// get rec from other screen space
	// get this one in screen space
	
	// call rectangle here

	return false;
}
