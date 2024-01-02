#include "Visualisation.h"
int width{ 1280 };
int height{ 720 };



void Blit(BYTE* screen, BYTE* texture, int textureWidth, int textureHeight, int posX, int posY)
{
	BYTE* tempScreenPrter = screen + (posY*posY*width)*4;
	BYTE* tempTexturePrter = texture;

	for (int y = 0; y < textureHeight; y++) {
		memcpy(tempScreenPrter, tempTexturePrter, textureWidth*4);
		tempTexturePrter += textureWidth * 4;
		tempScreenPrter += width*4;
	}

	



}

