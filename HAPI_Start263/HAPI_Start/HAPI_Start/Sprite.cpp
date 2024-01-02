#include "Sprite.h"

bool Sprite::Create(const std::string& filename, int numFrames, int frameWidth)
{
	if (!HAPI.LoadTexture(filename, &texture, width, height))
	{
        // erorr handling overall
		HAPI.UserMessage("Texture loading failure", "Error");
        return false;
    }
    return true;
}

void Sprite::Draw(BYTE* screen, Rectangle rscreen, int screenWidth, int sx, int sy, int frameNum, BYTE globalAlpha) 
{
    // make it so that the rectangle on the sprite sheet increments each frame with 
    // 64pix each time, so that we can go 64 pixels through each frame in the animation
    // sprite sheet.

    Rectangle textureRect(0, 0, width, height);
    textureRect.Translate(sx, sy);
    textureRect.ClipTo(rscreen);
    textureRect.Translate(-sx, -sy);

    if (sy < 0) sy = 0;
    if (sx < 0) sx = 0;

    int screenOffset = (sy * screenWidth + sx) * 4;
    int textureOffset = (textureRect.top * width + textureRect.left) * 4;

    int EOLScreenOffset = (screenWidth - textureRect.Width()) * 4;
    int EOLTextureOffset = (width - textureRect.Width()) * 4;

    for (int y = 0; y < textureRect.Height(); y++) {
        for (int x = 0; x < textureRect.Width(); x++) {

            BYTE* tempScreenPtr = screen + screenOffset;
            BYTE* tempTexturePtr = texture + textureOffset;

            BYTE pixelAlpha = tempTexturePtr[3];
            BYTE effectiveAlpha = (pixelAlpha * globalAlpha) / 255;

            if (effectiveAlpha == 255) {
                memcpy(tempScreenPtr, tempTexturePtr, 4);
            }
            else if (effectiveAlpha > 0) {
                tempScreenPtr[0] = tempScreenPtr[0] + ((effectiveAlpha * (tempTexturePtr[0] - tempScreenPtr[0])) >> 8);
                tempScreenPtr[1] = tempScreenPtr[1] + ((effectiveAlpha * (tempTexturePtr[1] - tempScreenPtr[1])) >> 8);
                tempScreenPtr[2] = tempScreenPtr[2] + ((effectiveAlpha * (tempTexturePtr[2] - tempScreenPtr[2])) >> 8);
            }

            screenOffset += 4;
            textureOffset += 4;
        }
        screenOffset += EOLScreenOffset;
        textureOffset += EOLTextureOffset;
    }
}
