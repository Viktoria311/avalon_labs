#pragma once

#include "const.h"



void init_field(char* field,
				//bool& game_on,
				bool food_flag,
				unsigned int& food_x,
				unsigned int& food_y,
				unsigned int snake_size,
				const unsigned int* snake_x,
				const unsigned int* snake_y);

void print_field(const char* field);
void clear_field(char* field);
void init_borders(char* field);
