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

	int e_x;
	int e_y;
	
	bool Awake;
	// is active bool

	float health;
public:
	Entity(int entityX, int entityY, bool Awake, const std::string& name) : 
		e_x(entityX), e_y(entityY), Awake(Awake), spriteName(name) {};

	virtual void Update() = 0;
	void Render(GraphicsEngine& graphics, float s);

	// wip
	virtual int GetPositionX() const { return e_x; }
	virtual int GetPositionY() const { return e_y; }
	virtual void SetPosition(int newX, int newY) { e_x = newX; e_y = newY; }
	
	// fixed 
	virtual ESide GetSide() const = 0;

	bool IsEnemyOf(Entity* other) const;
	bool CheckCollisionAgainst(Entity* other) const;


};

