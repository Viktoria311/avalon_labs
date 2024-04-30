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
	// Массив игрового поля
	char field[rows][columns] = { // Массив игрового поля
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
	// field[0] это указатель на первый элемент первой строки
	//j - тый элемент к - той строки, это и есть(k * b + j) - тый элемент в массиве
	// int FUNC(int a, int b, int *arr)
	//for (int i = 0; i < a; i++)
	//{
	//	for (int j = 0; j < b; j++)
	//		proizv *= arr[k * b + j];
	//}
	unsigned int step;
	
	// вместо глобальных переменных используются локальные
	// Признак, что еда установлена
	bool food_flag = false;
	// Координата еды по  горизонтали (X)
	unsigned int food_x;
	// Координата еды по  вертикали (Y)
	unsigned int food_y;
	// Таймаут задержки между шагами игры
	unsigned int timeout = 1000; // >100 (ms)
	// Признак продолжения игры
	bool game_on = true;
	// Текущий размер змейки
	unsigned int snake_size = 1;
	// Направление движения змейки
	DIRECTION direction = DIRECTION_RIGHT;
	// массив координат. индексы поля где есть змейка. индекс головы [0]. 
	unsigned int snake_x[L];
	// массив координат змейки в поле игры(по вертикали).
	unsigned int snake_y[L];

	// предыдущее положение кончика хвоста по оси 
	unsigned int last_tail_x;
	// предыдущее положение кончика хвоста по оси 
	unsigned int last_tail_y;



	init_game(snake_x, snake_y);
	init_field(field[0], /* game_on,*/ food_flag, food_x, food_y, snake_size, snake_x, snake_y);
	generate_food(field[0], game_on, food_flag, food_x, food_y);
	print_field(field[0]); // приглашение в игру

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // выбор направления

		handle_cmd(step, direction);

		move_snake(game_on, food_flag, food_x, food_y, step, direction, snake_size, snake_x, snake_y, last_tail_x, last_tail_y);

		init_field(field[0], /*game_on,*/ food_flag, food_x, food_y, snake_size, snake_x, snake_y); // наново заполняем поле игры символами

		generate_food(field[0], game_on, food_flag, food_x, food_y);

		print_field(field[0]);
	}
	std::cout << "BYE" << std::endl;

	return 0;
}

// 1) исправить алгоритмы всех функций, куда передаю field[0]