#include "World.h"

#undef main

World world;

int main(int* argc, char* argv[])
{
	srand((NULL));
	world.init();

	while (true)
	{
		world.run();
	}
	return 0;
}