#pragma once

#include "const.h"


void init_snake(unsigned int& snake_size, 
				unsigned int* snake_x);

void move_snake(char**& field, 
				bool& game_on,
				const unsigned int& rows, 
				const unsigned int& columns,
				bool& food_flag,
				const unsigned int& food_x, 
				const unsigned int& food_y,
				const unsigned int& step,
				DIRECTION direction,
				unsigned int& snake_size,
				unsigned int* snake_x, 
				unsigned int* snake_y,
				unsigned int& last_tail_x,
				unsigned int& last_tail_y);

void add_tail(const unsigned int& step,
			unsigned int snake_size,
			unsigned int* snake_x,
			unsigned int* snake_y,
			const unsigned int& last_tail_x,
			const unsigned int& last_tail_y);

bool are_sequentially(unsigned int snake_size,
					const unsigned int* const snake_x); // рядом ли элементы змейки друг к другу