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
	char** field = nullptr;

	unsigned int columns;
	unsigned int rows;
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


	create_field(field, rows, columns);
	init_game(snake_x, snake_y);
	init_field(field, rows, columns, food_flag, food_x, food_y, snake_size, snake_x, snake_y);
	generate_food(field, rows, columns, game_on, food_flag, food_x, food_y);
	print_field(const_cast<const char**>(field), rows, columns); // приглашение в игру

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // выбор направления

		handle_cmd(step, direction);

		move_snake(field, game_on, rows, columns, food_flag, food_x, food_y, step, direction, snake_size, snake_x, snake_y, last_tail_x, last_tail_y);

		init_field(field, rows, columns, food_flag, food_x, food_y, snake_size, snake_x, snake_y); // наново заполняем поле игры символами

		generate_food(field, rows, columns, game_on, food_flag, food_x, food_y);

		print_field(const_cast<const char**>(field), rows, columns);
	}

	destroy_field(field, rows, columns);

	std::cout << "BYE" << std::endl;

	return 0;
}

// 1) исправить алгоритмы всех функций, куда передаю field[0]