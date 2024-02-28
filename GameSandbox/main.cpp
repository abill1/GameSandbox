
#include "Game/Game.h"

int main()
{
	ABFramework::MemoryTracker::Init();
    ABFramework::Code retCode = ABFramework::Code::SUCCESS;
	ABFramework::Game game("Hello World", 1200, 900);
	retCode = game.Run();

	return (int)retCode;
}

