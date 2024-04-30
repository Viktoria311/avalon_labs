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
	char field[columns] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; // Массив игрового поля
	unsigned int step;
	
	// вместо глобальных переменных используются локальные
	// Признак, что еда установлена
	bool food_flag = false;
	// Координата еды по  горизонтали (X)
	unsigned int food_x;
	// Таймаут задержки между шагами игры
	unsigned int timeout = 1000; // >100 (ms)
	// Признак продолжения игры
	bool game_on = true;
	// Текущий размер змейки
	unsigned int snake_size = 1;
	// Направление движения змейки
	DIRECTION direction = DIRECTION_RIGHT;
	// массив координат. индексы поля где есть змейка. индекс головы [0]. 
	unsigned int snake_x[L]; // = { 0 };  

	init_game(snake_x);
	generate_food(field, game_on, food_flag, food_x);
	init_field(field, food_flag, food_x, snake_size, snake_x);
	print_field(field); // приглашение в игру

	while (game_on && _getch() != ESC)
	{
		step = _getch(); // выбор направления

		handle_cmd(step, direction);

		move_snake(game_on, food_flag, food_x, step, direction, snake_size, snake_x);

		init_field(field, food_flag, food_x, snake_size, snake_x); // наново заполняем поле игры символами

		generate_food(field, game_on, food_flag, food_x);

		print_field(field);
	}
	std::cout << "BYE" << std::endl;

	return 0;
}
