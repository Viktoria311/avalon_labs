#pragma once

#include "const.h"

// обязательно ссылка
void create_field(char**& field, unsigned int& rows, unsigned int& columns);

// обязательно ссылка
void destroy_field(char**& field, const unsigned int& rows, const unsigned int& columns);

void init_field(char** field,
				const unsigned int& rows, 
				const unsigned int& columns,
				//bool& game_on,
				bool food_flag,
				unsigned int& food_x,
				unsigned int& food_y,
				unsigned int snake_size,
				const unsigned int* snake_x,
				const unsigned int* snake_y);

void print_field(const char** field, const unsigned int& rows, const unsigned int& columns);
void clear_field(char** field, const unsigned int& rows, const unsigned int& columns);
void init_borders(char** field, const unsigned int& rows, const unsigned int& columns);
