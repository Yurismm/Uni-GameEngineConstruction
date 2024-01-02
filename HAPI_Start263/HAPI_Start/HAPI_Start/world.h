#pragma once

#include <vector>

class Entity;
class GraphicsEngine;
class Player;

class world
{
private:
	GraphicsEngine* w_graphics{ nullptr };
	// working with poly-morphism
	std::vector<Entity*> entityVec;
	
	void LevelLoad();
	Player* newPlayer{ nullptr };
	// null pointer here

public:
	~world();
	void Run();

};

