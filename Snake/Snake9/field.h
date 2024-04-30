#pragma once

#include "const.h"

struct food;
struct snake;

struct field
{
	// ћассив игрового пол€
	char** Field;

	// ƒлина игрового пол€ по горизонтали
	unsigned int columns;

	// ƒлина игрового пол€ по вертикали
	unsigned int rows;
};

// об€зательно ссылка
void create_field(field& my_field);

// об€зательно ссылка
void destroy_field(field& my_field);

void init_field(field& my_field,
				food& my_food,
				snake& my_snake);

void print_field(const field& my_field);
void clear_field(field& my_field);
void init_borders(field& my_field);
