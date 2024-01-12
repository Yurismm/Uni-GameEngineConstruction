#pragma once

#include <HAPI_lib.h>
#include <iostream>
#include "Sprite.h"

using namespace HAPISPACE;

class Visualisation {
    BYTE* screen;

    int screenWidth;
    int screenHeight;

public:

    Visualisation(BYTE* s, int w, int h) : screen(s), screenWidth(w), screenHeight(h) {};
    void Blit(BYTE* screen, BYTE* texture, int textureWidth, int textureHeight, int posX, int posY);

};