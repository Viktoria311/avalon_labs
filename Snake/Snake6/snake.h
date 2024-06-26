#pragma once

#include "const.h"


void init_snake(unsigned int& snake_size, 
				unsigned int* snake_x);

void move_snake(bool& game_on,
				bool& food_flag,
				const unsigned int& food_x,
				const unsigned int& step,
				DIRECTION direction,
				unsigned int& snake_size,
				unsigned int* snake_x);

void add_tail(const unsigned int& step,
			unsigned int snake_size,
			unsigned int* snake_x);

bool are_sequentially(unsigned int snake_size,
					const unsigned int* const snake_x); // ����� �� �������� ������ ���� � �����