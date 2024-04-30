#pragma once

#include "const.h"

struct snake;
struct field;
struct food;

struct Game
{
	// Таймаут задержки между шагами игры
	unsigned int timeout = 1000; // >100 (ms)

	// Признак продолжения игры
	bool game_on = true;
};

void init_game(snake& my_snake);

void set_snake(field& my_field,
				snake& my_snake);

void set_food();

void check_game();
void check_snake();
bool check_eating(snake& my_snake,
					food& my_food);

void clear_snake();
void handle_cmd(const unsigned int& step, snake& my_snake);
