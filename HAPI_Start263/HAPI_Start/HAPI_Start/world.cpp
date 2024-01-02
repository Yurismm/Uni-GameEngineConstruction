#include "world.h"
#include "GraphicsEngine.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "BackgroundEntity.h"

#include <vector>

using namespace HAPISPACE;

const DWORD kTimeBetweenTicks{ 1000/60 }; // 20 times a second

void world::LevelLoad()
{
	// hard coded creation of levels	
	// load some sprites with the graphics
	// create world entities and tell them what sprites to use

	// NOTE -> THE ORDER OF THE ENTITIES DETIRMINES WHICH ONE
	// OVERLAYS WHICH
	// TODO: creation of level design
		
	// BACKGROUND ENTITIES
	BackgroundEntity* Background = new BackgroundEntity(0, 0);
	entityVec.push_back(Background);

	// MAIN ENTITIES
	// player entity
	Player* newPlayer = new Player(1000, 500);
	entityVec.push_back(newPlayer);

	// enemy entity(ies)
	Enemy* newEnemy = new Enemy(200,100);
	entityVec.push_back(newEnemy);

}

world::~world() 
{
	delete w_graphics;
}


void world::Run()
{
	// everything in main can go in here
	int width = 1280;
	int height = 720;

	w_graphics = new GraphicsEngine(width, height);
	
	LevelLoad();

	if (!w_graphics->Initialise()) {
		delete w_graphics; 
		return;
	}

	w_graphics->SetShowFPS(true);

	w_graphics->GetScreen();

	DWORD lastUpdateTime{ 0 };
	
	while (HAPI.Update()) {
		DWORD timeNow = HAPI.GetTime();

		if (timeNow - lastUpdateTime >= kTimeBetweenTicks) {
			for (Entity* entity : entityVec)
				entity->Update();

			lastUpdateTime = HAPI.GetTime();

			for (size_t i = 0; i < entityVec.size(); i++)
			{
				for (size_t j = i + 1; j < entityVec.size(); j++)
				{
					// checking i vs j
					if (entityVec[i]->IsEnemyOf(entityVec[j]))
					{
						/// reduce health of the entity until they die?

					}
				};
			};
		};
	
		float s = kTimeBetweenTicks / (float)(timeNow - lastUpdateTime);

		w_graphics->ClearScreen();

		for (Entity* entity : entityVec)
			entity->Render(*w_graphics, s);
		//check game win/loss condition
	}
}
