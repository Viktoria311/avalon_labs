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
	snake my_snake;
	food my_food;
	field my_field;
	Game my_game;

	unsigned int step;
	
	// ���������� ��������� ������� ������ �� ��� 
	unsigned int last_tail_x;
	// ���������� ��������� ������� ������ �� ��� 
	unsigned int last_tail_y;


	create_field(my_field);
	init_game(my_snake);
	init_field(my_field, my_food, my_snake);
	generate_food(my_field, my_game, my_food);
	print_field(const_cast<const field&>(my_field)); // ����������� � ����

	while (my_game.game_on && _getch() != ESC)
	{
		step = _getch(); // ����� �����������

		handle_cmd(step, my_snake);

		move_snake(my_game, my_field, my_food, step, my_snake, last_tail_x, last_tail_y);

		init_field(my_field, my_food, my_snake); // ������ ��������� ���� ���� ���������

		generate_food(my_field, my_game, my_food);

		print_field(const_cast<const field&>(my_field));
	}

	destroy_field(my_field);

	std::cout << "BYE" << std::endl;

	return 0;
}

// 1) ��������� ��������� ���� �������, ���� ������� field[0]