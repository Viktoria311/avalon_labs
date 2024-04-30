#include "field.h"
#include "food.h"
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <iostream>



void init_field(char* field, 
				bool food_flag,
				unsigned int& food_x, 
				unsigned int snake_size, 
				const unsigned int* snake_x)
{
	/*
	Х	√раница пол€ заполн€етс€ символом границы (например, С*Т).
	Х	¬ызов функции clear_field();
	*/
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	clear_field(field); // пробелы по полю

	if (food_flag == true)
		field[food_x] = food_symbol;

	set_snake(field, snake_size, snake_x);
}

void print_field(char* field)
{
	/*
	Х	ќчистка экрана  setCursorPosition().
	Х	ћассив игрового пол€ выводитс€ на экран.
	*/
	setCursorPosition(0, 0);

	for (int i = 0; i < columns; ++i)
	{
		std::cout << border_symbol;
	}
	std::cout << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << field[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << border_symbol;
	}
	std::cout << std::endl;
}

void clear_field(char* field)
{
	/*
	ћассив игрового пол€ заполн€етс€ символом-заполнителем (например, пробелом).
	*/
	for (int i = 1; i < columns - 1; ++i) // пробелы по всему полю
		field[i] = field_symbol;
}
