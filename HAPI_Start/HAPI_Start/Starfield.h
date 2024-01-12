#pragma once
#include "GraphicsEngine.h"


class Star
{
public:


	float x, y, z;
	Star() : x(1000), y(600), z(500) {};


};

class Starfield
{

private:


	Star* stars;
	int numStars;
	GraphicsEngine& graphics;


public:


	Starfield(GraphicsEngine& g, int num) : graphics(g), numStars(num) {
		stars = new Star[numStars];
	};


	~Starfield(){
		delete[] stars;
	}


	void Update(const HAPI_TKeyboardData& keyData);
	void Render();


};
