#pragma comment(lib,"opengl32.lib")

#include "Game.h"

int main()
{
	Game& game = Game();
	game.init();
	game.run();
	return EXIT_SUCCESS;
}