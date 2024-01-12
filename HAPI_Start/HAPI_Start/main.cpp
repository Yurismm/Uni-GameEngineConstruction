#include <HAPI_lib.h>
#include <iostream>
#include <filesystem>
#include "GraphicsEngine.h"
#include "Sprite.h"
#include "world.h"

using namespace HAPISPACE;

/*

								NOTES

IMPORTANT INFOMATION ABOUT GAME
	- GAME RUNS IN 1280 X 720PX
	- GAME RUNS IN 60FPS / UPDATES A SECOND
	- AREA OF DEATH IS -> 504,2 AND 775,718

TODO: Make sprites

TODO: Create error handler Interface
TODO: Make a scrolling background to make it seem there is movement
		- Background will scroll upwards, 
		- Make sure that you can find the y part of the end of the sprite
		- Calculate where that is then add another sprite there

TODO: Simulation classes / World Model
		- For example, like the bullets, enemies and their positions and etc.
		- Can load in levels
		- Check win and loss conditions
		- Checks collision (detections)
		- Calls from other systems (eg graphics)
		- Health, etc
		- AI
		- Entity death flagging
		- Inheritance


*/

/*

								KNOWN BUGS
SEVERE: 

MINOR:
		- Weird stuttering during movement of entity
FIXED:	- Error for exeption above originates - HandleInput()
		- Can't see the fps counter I don't think, though I think the graphics class works fine since
		- Player Creation won't work, most likely due to some pointer issues;
			-> Exception thrown at 0x00007FF9FC42024E (ucrtbased.dll) in HAPI_Start.exe: 0xC0000005: Access violation reading location 0xFFFFFFFFFFFFFFFF.
			UPDATES:
				-> I no longer get the error though I can see that it does load the world creation correctly
				-> Though do review HandleInput()
*/

/*

								PLANNER
FINISHED:
		- Graphics Engine
		- Fixed error above, Apparently I was deleting the graphics near the end
		- of the code
		- HandleGraphics
		- Add sprite to character to display on screen
		- Ensure that the pointer is correct.
		- HandleGraphics
		- Find sprites
		- Work on scrolling background for the game
		- Work on sprite collisions
WORKING ON:
		- Pointer management
		- Commenting
NEED TO DO NOW:
		- Death conditions and win conditions for game
		- Game logic
		- AI
		- Polishing
			- add a menu possibly?
		- Report
*/

// screen size
int width{ 1280 };
int height{ 720 };


void HAPI_Main()
{
	/*GraphicsEngine graphics(width,height);*/
	world* newWorld = new world;

	newWorld->Run();
	delete newWorld;

	std::cout << "Game Started" << std::endl;
};