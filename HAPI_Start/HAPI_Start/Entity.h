#pragma once
// TODO fix entity classes - CTRL + B;
#include "GraphicsEngine.h"
#include "Entity.h"
#include <vector>

enum class ESide 
{
	eNeutral,
	ePlayer,
	eEnemy
};

using namespace std;

class GraphicsEngine;

class Entity
{
private:

protected:
	// positions 
	string spriteName;

	//include old positions 
	//TODO: Use VECTORS for position checks later down
	//the line

	int OLDe_x;
	int OLDe_y;
	// for interpolation later?

	int e_x;
	int e_y;
	
	bool Alive;
	// is active bool

	float health;
	// a lot of health would be 100
	// damage maybe done in increments of 10
public:
	Entity(int entityX, int entityY, bool Awake, const std::string& name, float health) : 
		e_x(entityX), e_y(entityY), Alive(Awake), spriteName(name), health(health) {};

	virtual void Update() = 0;
	void Render(GraphicsEngine& graphics, float s);

	// wip
	virtual int GetPositionX() const { return e_x; }
	virtual int GetPositionY() const { return e_y; }
	virtual void SetPosition(int newX, int newY) { e_x = newX; e_y = newY; }
	virtual string GetSpriteName() const { return spriteName; }
	virtual void ReduceHealth(float damage) { health -= damage; if (health <= 0) { Alive = false; } }
	virtual float GetHealth() { return health; }
	virtual bool IsAlive() { if (health == 0) { Alive = false; return false; } Alive = true; return true; }
	
	// fixed
	virtual ESide GetSide() const = 0;

	bool IsEnemyOf(Entity* other) const;
	bool CheckCollisionAgainst(Entity* other) const;


};

