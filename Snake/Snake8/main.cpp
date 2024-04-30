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
	char** field = nullptr;

	unsigned int columns;
	unsigned int rows;
	unsigned int step;
	
	// ������ ���������� ���������� ������������ ���������
	// �������, ��� ��� �����������
	bool food_flag = false;
	// ���������� ��� ��  ����������� (X)
	unsigned int food_x;
	// ���������� ��� ��  ��������� (Y)
	unsigned int food_y;
	// ������� �������� ����� ������ ����
	unsigned int timeout = 1000; // >100 (ms)
	// ������� ����������� ����
	bool game_on = true;
	// ������� ������ ������
	unsigned int snake_size = 1;
	// ����������� �������� ������
	DIRECTION direction = DIRECTION_RIGHT;
	// ������ ���������. ������� ���� ��� ���� ������. ������ ������ [0]. 
	unsigned int snake_x[L];
	// ������ ��������� ������ � ���� ����(�� ���������).
	unsigned int snake_y[L];

	// ���������� ��������� ������� ������ �� ��� 
	unsigned int last_tail_x;
	// ���������� ��������� ������� ������ �� ��� 
	unsigned int last_tail_y;


	create_field(field, rows, columns);
	init_game(snake_x, snake_y);
	init_field(field, rows, columns, food_flag, food_x, food_y, snake_size, snake_x, snake_y);
	generate_food(field, rows, columns, game_on, food_flag, food_x, food_y);
	print_field(const_cast<const char**>(field), rows, columns); // ����������� � ����

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // ����� �����������

		handle_cmd(step, direction);

		move_snake(field, game_on, rows, columns, food_flag, food_x, food_y, step, direction, snake_size, snake_x, snake_y, last_tail_x, last_tail_y);

		init_field(field, rows, columns, food_flag, food_x, food_y, snake_size, snake_x, snake_y); // ������ ��������� ���� ���� ���������

		generate_food(field, rows, columns, game_on, food_flag, food_x, food_y);

		print_field(const_cast<const char**>(field), rows, columns);
	}

	destroy_field(field, rows, columns);

	std::cout << "BYE" << std::endl;

	return 0;
}

// 1) ��������� ��������� ���� �������, ���� ������� field[0]