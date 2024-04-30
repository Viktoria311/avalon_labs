#include "field.h"
#include "food.h"
#include "const.h"
#include "game.h"
#include "snake.h"
#include "winconsole.h"
#include <iostream>


void create_field(field& my_field)
{
	my_field.columns = 10;
	my_field.rows = 10;

	my_field.Field = new char* [my_field.rows];

	for (int i = 0; i < my_field.rows; ++i)
		my_field.Field[i] = new char[my_field.columns];


}

void destroy_field(field& my_field)
{
	for (int i = 0; i < my_field.rows; ++i)
	{
		delete my_field.Field[i];
		my_field.Field[i] = nullptr;
	}
	
	delete my_field.Field;
}

void init_field(field& my_field,
				food& my_food,
				snake& my_snake)
{
	/*
	•	Граница поля заполняется символом границы (например, ‘*’).
	•	Вызов функции clear_field();
	*/

	init_borders(my_field);// рамка
	clear_field(my_field); // пробелы по полю
	
	set_snake(my_field, my_snake);

	if (my_food.food_flag == true)
		my_field.Field[my_food.food_y] [my_food.food_x] = food_symbol;
}

void print_field(const field& my_field)
{
	/*
	•	Очистка экрана  setCursorPosition().
	•	Массив игрового поля выводится на экран.
	*/
	setCursorPosition(0, 0);
	// БЫЛО
	/*
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

	*/
	// СТАЛО
	for (int i = 0; i < my_field.rows; ++i)
	{
		for (int j = 0; j < my_field.columns; ++j)
			std::cout << my_field.Field[i ] [ j];

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void clear_field(field& my_field)
{
	/*
	Массив игрового поля заполняется символом-заполнителем (например, пробелом).
	*/
	// БЫЛО
	//for (int i = 1; i < columns - 1; ++i) // пробелы по всему полю
	//	field[i] = field_symbol;

	// СТАЛО



	//  пробелы по всему полю. заполняем серединку поля
	for (int i = 1; i < my_field.rows - 1; ++i)
	{
		for (int j = 1; j < my_field.columns - 1; ++j)
			//if (j != 0 && j != columns - 1)
			my_field.Field[i] [j] = field_symbol;// номер текущей строки * columns + номер текущего символа

	}

}

void init_borders(field& my_field)
{
	// заполняем края поля сверху 
	for (int j = 0; j < my_field.columns; ++j)
		my_field.Field[0] [j] = border_symbol;
	///*
	//  пробелы по всему полю. заполняем оконтовку поля
	for (int i = 1; i < my_field.rows - 1; ++i)
	{
		for (int j = 0; j < my_field.columns; ++j)
			if (j == 0 || j == my_field.columns - 1)
				my_field.Field[i] [j] = border_symbol;
	}
	//*/
	/*
	или так  оконтовка слева и справа по-отдельности
	for (int i = 1; i < rows - 1; ++i)
		field[i * columns] = border_symbol;

	for (int i = 1; i < rows - 1; ++i)
		field[i * columns + columns - 1] = border_symbol;
	*/

	// заполняем края поля снизу
	for (int j = 0; j < my_field.columns; ++j)
		my_field.Field[(my_field.rows - 1)] [j] = border_symbol;

}