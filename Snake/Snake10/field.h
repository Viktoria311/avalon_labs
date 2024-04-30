#pragma once

#include "const.h"

struct Game;


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
void create_field(Game& my_game);

// об€зательно ссылка
void destroy_field(Game& my_game);

void init_field(Game& my_game);

void print_field(const Game& my_game);
void clear_field(Game& my_game);
void init_borders(Game& my_game);
