#include "game.h"
#include "snake.h"
#include "const.h"
#include "field.h"
#include "food.h"
#include "winconsole.h"
#include <iostream>
#include <windows.h>
#include <conio.h>


int main()
{
	unsigned int step;

	init_game();
	generate_food();
	init_field();
	print_field(); // приглашение в игру

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // выбор направления

		handle_cmd(step);

		move_snake(step);

		init_field(); // наново заполняем поле игры символами
		
		generate_food();

		print_field();
	}
	std::cout << "BYE" << std::endl;

	return 0;
}