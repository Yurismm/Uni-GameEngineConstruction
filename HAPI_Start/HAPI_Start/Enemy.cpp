#include "Entity.h"
#include "Enemy.h"
#include "GraphicsEngine.h"
#include "Sprite.h"

using namespace HAPISPACE;

Enemy::Enemy(int entityX, int entityY, float heatlh) : Entity(entityX, entityY, true, "enemySprite", health) {};


void Enemy::Update()
{

}
