#include "Game.h"

#include <cstdlib>

int Game::die(int pip_num, int num_rolled)
{
	auto const result = rand() % (pip_num + 1) * num_rolled;

	return result;
}
