#include "Starfield.h"

void Starfield::Update(const HAPI_TKeyboardData& keyData)
{
	//
}

void Starfield::Render()
{
    BYTE* screen = graphics.GetScreen();
    int width = 1280;
    int height = 720; 

    graphics.ClearScreen();

    for (int i = 0; i < numStars; i++) {

		Star& star = stars[i];

		// turn the 3D star location into 2D screen location with equation from hints
		int Sx = ((EDistance * (star.x - cx)) / (star.z + EDistance)) + cx;
		int Sy = ((EDistance * (star.y - cy)) / (star.z + EDistance)) + cy;

		// offset
		int offset = (Sx + Sy * width) * 4;

		// put the star on the screen, and make sure it fits in the screen to prevent crashing
		if (Sx >= 0 && Sx < width && Sy >= 0 && Sy < height) {
			screen[offset] = 255;      // r
			screen[offset + 1] = 255;  // g
			screen[offset + 2] = 255;    // b
			// white seems to look better than yellow here
			// no alpha needed
		}
		else {
			star.x = (rand() % (2 * width)) - width / 2;
			star.y = (rand() % (2 * height)) - height / 2;
			star.z = 500;
			continue;
			// makes it look more smooth than checking if it is less than eye distance as it
			// will check if it is outside the bounds and reset it
		}

		// move the star closer 
		star.z -= 2;

    }

}
