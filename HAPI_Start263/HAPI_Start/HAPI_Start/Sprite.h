#pragma once
#include <HAPI_lib.h>
#include <iostream>
#include "Rectangle.h"

using namespace HAPISPACE;

class Sprite {
private:
    BYTE* texture;
    int width, height;
    BYTE alpha;
    int rames{ 1 };
    int frameWidth{ 0 };

public:
    bool Create(const std::string& filename, int numFrames, int frameWidth);
    // add flagging like fastblit etc // x and y value for where on the screen
    void Draw(BYTE* screen, Rectangle rscreen, int screenWidth, int sx, int sy, int frameNum, BYTE globalAlpha = 255);
};

