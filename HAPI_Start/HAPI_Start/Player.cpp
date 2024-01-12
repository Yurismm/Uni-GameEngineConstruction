#include "Player.h"
#include "Entity.h"
#include "World.h"
#include "GraphicsEngine.h"
#include "Sprite.h"

using namespace HAPISPACE;

Player::Player(int entityX, int entityY, float health) : Entity(entityX, entityY, true, "playerSprite", health) {};

void Player::Update()
{
	const HAPI_TKeyboardData& keyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& controllerData = HAPI.GetControllerData(0);

	// TODO:: add an ENUM here maybe
	bool PadUp = controllerData.digitalButtons[HK_DIGITAL_DPAD_UP];
	bool PadDown = controllerData.digitalButtons[HK_DIGITAL_DPAD_DOWN];
	bool PadLeft = controllerData.digitalButtons[HK_DIGITAL_DPAD_LEFT];
	bool PadRight = controllerData.digitalButtons[HK_DIGITAL_DPAD_RIGHT];

	// TODO:: interpolate the values to make the movement more smooth looking in final

	// Keyboard and pad inputs
	if (keyData.scanCode['W'] || PadUp && e_y > 0) {
		e_y -= movementSpeed;
	}
	if (keyData.scanCode['A'] || PadLeft && e_x > 0) {
		e_x -= movementSpeed;
	}
	if (keyData.scanCode['S'] || PadDown && e_y) {
		e_y += movementSpeed;
	}
	if (keyData.scanCode['D'] || PadRight && e_x) {
		e_x += movementSpeed;
	}

}
