#pragma once

#include "const.h"

//extern unsigned int timeout; // >100 (ms)

//extern bool game_on;


void init_game(unsigned int* snake_x);

void set_snake(char* field,
				unsigned int snake_size,
				const unsigned int* const snake_x);

void set_food();

void check_game();
void check_snake();
bool check_eating(unsigned int& snake_size,
				const unsigned int* const snake_x,
				bool& food_flag,
				const unsigned int& food_x);

void clear_snake();
void handle_cmd(const unsigned int& step, DIRECTION& direction);
