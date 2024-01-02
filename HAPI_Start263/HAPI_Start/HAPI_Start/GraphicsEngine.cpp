#include "GraphicsEngine.h"
#include "Sprite.h"
#include "Rectangle.h"

bool GraphicsEngine::Initialise()
{
	if(!HAPI.Initialise(width, height)){
		HAPI.UserMessage("Init failure", "Error");
		return false;
	}
	screen = HAPI.GetScreenPointer();

	// init all the sprites here
	if (!CreateSprite("Data/BackgroundEntity.tga", "BackgroundEntity"))
	{
		HAPI.UserMessage("Texture not found - BackgroundEntity", "Error");
		return 0;
	}
	if (!CreateSprite("Data/PlayerCar.tga", "playerSprite"))
	{
		HAPI.UserMessage("Texture not found - Playersprite", "Error");
		return 0;
	}
	if (!CreateSprite("Data/EnemyCar.tga", "enemySprite"))
	{
		HAPI.UserMessage("Texture not found - EnemySprite", "Error");
		return 0;
	}

	return true;
}

void GraphicsEngine::ClearScreen()
{
	memset(screen, 40, width * height * 4);
}

bool GraphicsEngine::LoadTexture(const std::string& file, BYTE** textureData,int& textureWidth, int& textureHeight)
{
	// recheck this on pc there is an issue with the file loading possibly could add the name ask keith
	return HAPI.LoadTexture(file, textureData, textureWidth, textureHeight);
}

void GraphicsEngine::SetShowFPS(bool show)
{
	HAPI.SetShowFPS(show);
}

bool GraphicsEngine::CreateSprite(const std::string& filename, const std::string& name)
{
	Sprite *newSprite = new Sprite();
	if (!newSprite->Create(filename,1,0)) {
		return false;
	}
	spritemap[name] = newSprite;
	return true;
}

void GraphicsEngine::DrawSprite(const std::string& name, int sx, int sy)
{
	//make sure that there is a find first before this
	//std find works
	//err check here
	//search for the sprite in the spritemap
	auto it = spritemap.find(name);

	// check find sprite
	if (it != spritemap.end()) {
		// get the sprite pointer and draw the sprite
		Sprite* sprite = it->second;
		if (sprite) {
			Rectangle screenRect(0, 0, width, height);
			BYTE globalAlpha = 255;
			sprite->Draw(screen, screenRect, width, sx, sy, globalAlpha);
		}
	}
	else {
		HAPI.UserMessage("Sprite not found", "Error");
		// maybe add the name of the sprite that awasnt foudn 
	}
}
