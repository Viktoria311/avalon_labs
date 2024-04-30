#include "game.h"
#include "snake.h"
#include "const.h"
#include "field.h"
#include "food.h"
#include <iostream>


int main()
{
	Game my_game;

	init_game(my_game);
	
	exec_game(my_game);

	destroy_field(my_game);

	std::cout << "BYE" << std::endl;

	return 0;
}
