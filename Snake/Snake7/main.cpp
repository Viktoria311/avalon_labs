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
	char field[rows][columns] = { // ������ �������� ����
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
	};
	// field[0] ��� ��������� �� ������ ������� ������ ������
	//j - ��� ������� � - ��� ������, ��� � ����(k * b + j) - ��� ������� � �������
	// int FUNC(int a, int b, int *arr)
	//for (int i = 0; i < a; i++)
	//{
	//	for (int j = 0; j < b; j++)
	//		proizv *= arr[k * b + j];
	//}
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



	init_game(snake_x, snake_y);
	init_field(field[0], /* game_on,*/ food_flag, food_x, food_y, snake_size, snake_x, snake_y);
	generate_food(field[0], game_on, food_flag, food_x, food_y);
	print_field(field[0]); // ����������� � ����

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // ����� �����������

		handle_cmd(step, direction);

		move_snake(game_on, food_flag, food_x, food_y, step, direction, snake_size, snake_x, snake_y, last_tail_x, last_tail_y);

		init_field(field[0], /*game_on,*/ food_flag, food_x, food_y, snake_size, snake_x, snake_y); // ������ ��������� ���� ���� ���������

		generate_food(field[0], game_on, food_flag, food_x, food_y);

		print_field(field[0]);
	}
	std::cout << "BYE" << std::endl;

	return 0;
}

// 1) ��������� ��������� ���� �������, ���� ������� field[0]