#pragma once

#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"


struct Game
{
	snake my_snake;
	food my_food;
	field my_field;

	// Таймаут задержки между шагами игры
	unsigned int timeout = 1000; // >100 (ms)

	// Признак продолжения игры
	bool game_on = true;
};

void init_game(Game& my_game);

void next_step(Game& my_game);

void exec_game(Game& my_game);

void set_snake(Game& my_game);

void set_food();

void check_game();
void check_snake();
bool check_eating(Game& my_game);

void clear_snake();
void handle_cmd(const unsigned int& step, Game& my_game);
