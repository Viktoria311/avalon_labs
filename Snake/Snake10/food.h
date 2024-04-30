#pragma once


struct field;
struct Game;

struct food
{
	// Признак, что еда установлена
	bool food_flag = false;

	// Координата еды по  горизонтали (X)
	unsigned int food_x;

	// Координата еды по  вертикали (Y)
	unsigned int food_y;
};

void init_food();

void generate_food(Game& my_game);