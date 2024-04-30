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
	// ������ �������� ����
	char field[columns] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; // ������ �������� ����
	unsigned int step;
	
	// ������ ���������� ���������� ������������ ���������
	// �������, ��� ��� �����������
	bool food_flag = false;
	// ���������� ��� ��  ����������� (X)
	unsigned int food_x;
	// ������� �������� ����� ������ ����
	unsigned int timeout = 1000; // >100 (ms)
	// ������� ����������� ����
	bool game_on = true;
	// ������� ������ ������
	unsigned int snake_size = 1;
	// ����������� �������� ������
	DIRECTION direction = DIRECTION_RIGHT;
	// ������ ���������. ������� ���� ��� ���� ������. ������ ������ [0]. 
	unsigned int snake_x[L]; // = { 0 };  

	init_game(snake_x);
	generate_food(field, game_on, food_flag, food_x);
	init_field(field, food_flag, food_x, snake_size, snake_x);
	print_field(field); // ����������� � ����

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // ����� �����������

		handle_cmd(step, direction);

		move_snake(game_on, food_flag, food_x, step, direction, snake_size, snake_x);

		init_field(field, food_flag, food_x, snake_size, snake_x); // ������ ��������� ���� ���� ���������

		generate_food(field, game_on, food_flag, food_x);

		print_field(field);
	}
	std::cout << "BYE" << std::endl;

	return 0;
}
