
#include "./Engine/Engine.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	Framework::MemoryTracker::Init();
	Engine::Game game;
	game.Run();
	return 0;
}

