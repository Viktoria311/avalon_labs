#pragma once

#include "const.h"

//extern char field[columns];

void init_field(char* field,
				bool food_flag,
				unsigned int& food_x,
				unsigned int snake_size,
				const unsigned int* snake_x);

void print_field(char* field);
void clear_field(char* field);

