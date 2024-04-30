#pragma once

#include "const.h"

struct field;
struct food;
struct Game;


struct snake
{
	// Текущий размер змейки
	unsigned int snake_size = 1;

	// Направление движения змейки
	DIRECTION direction = DIRECTION_RIGHT;

	// массив координат. индексы поля где есть змейка. индекс головы [0]. 
	unsigned int snake_x[L];

	// массив координат змейки в поле игры(по вертикали).
	unsigned int snake_y[L];
};

void init_snake(snake& my_snake);

void move_snake(Game& my_game,
				const unsigned int& step);

void add_tail(const unsigned int& step,
			Game& my_game,
			const unsigned int& last_tail_x,
			const unsigned int& last_tail_y);

bool are_sequentially(unsigned int snake_size,
					const unsigned int* const snake_x); // рядом ли элементы змейки друг к другу