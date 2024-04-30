#pragma once

#include "const.h"


void init_game(unsigned int* snake_x, unsigned int* snake_y);

void set_snake(char* field,
				unsigned int snake_size,
				const unsigned int* const snake_x,
				const unsigned int* const snake_y);

void set_food();

void check_game();
void check_snake();
bool check_eating(unsigned int& snake_size,
				const unsigned int* const snake_x,
				const unsigned int* const snake_y,
				bool& food_flag,
				const unsigned int& food_x, 
				const unsigned int& food_y);

void clear_snake();
void handle_cmd(const unsigned int& step, DIRECTION& direction);
