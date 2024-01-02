#pragma once
#include <HAPI_lib.h>
#include <unordered_map>

using namespace HAPISPACE;

class Sprite;

class GraphicsEngine
{
private:
	BYTE* screen{ nullptr };
	// string is the key, and you want to look for the pointer to the sprite
	std::unordered_map<std::string, Sprite*> spritemap;
	int width;
	int height;
public:
	GraphicsEngine(int w, int h) : width(w), height(h){}

	bool CreateSprite(const std::string& filename, const std::string& name);
	void DrawSprite(const std::string& name, int sx, int sy);

	bool Initialise();
	BYTE* GetScreen() const { return screen; };
	void ClearScreen();
	bool LoadTexture(const std::string& file, BYTE** textureData,int& textureWidth, int& textureHeight);
	void SetShowFPS(bool show);

	Rectangle GetSpriteRect(const std::string& spriteName, int frameNum) const;
};

