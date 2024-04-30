#include "field.h"
#include "food.h"
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <iostream>


void create_field(char**& field, unsigned int& rows, unsigned int& columns)
{
	columns = 10;
	rows = 10;

	field = new char* [rows];

	for (int i = 0; i < rows; ++i)
		field[i] = new char[columns];


}

void destroy_field(char**& field, const unsigned int& rows, const unsigned int& columns)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] field[i];
		field[i] = nullptr;
	}
	
	delete[] field;
}

void init_field(char** field, 
				//bool& game_on,
				const unsigned int& rows, 
				const unsigned int& columns,
				bool food_flag,
				unsigned int& food_x, 
				unsigned int& food_y,
				unsigned int snake_size, 
				const unsigned int* snake_x, 
				const unsigned int* snake_y)
{
	/*
	•	Граница поля заполняется символом границы (например, ‘*’).
	•	Вызов функции clear_field();
	*/

	init_borders(field, rows, columns);// рамка
	clear_field(field, rows, columns); // пробелы по полю
	
	set_snake(field, rows, columns, snake_size, snake_x, snake_y);

	if (food_flag == true)
		field[food_y] [food_x] = food_symbol;
}

void print_field(const char** field, const unsigned int& rows, const unsigned int& columns)
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
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			std::cout << field[i ] [ j];

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void clear_field(char** field, const unsigned int& rows, const unsigned int& columns)
{
	/*
	Массив игрового поля заполняется символом-заполнителем (например, пробелом).
	*/
	// БЫЛО
	//for (int i = 1; i < columns - 1; ++i) // пробелы по всему полю
	//	field[i] = field_symbol;

	// СТАЛО



	//  пробелы по всему полю. заполняем серединку поля
	for (int i = 1; i < rows - 1; ++i) 
	{
		for (int j = 1; j < columns - 1; ++j)
			//if (j != 0 && j != columns - 1)
				field[i] [j] = field_symbol;// номер текущей строки * columns + номер текущего символа

	}

}

void init_borders(char** field, const unsigned int& rows, const unsigned int& columns)
{
	// заполняем края поля сверху 
	for (int j = 0; j < columns; ++j)
		field[0] [j] = border_symbol;
	///*
	//  пробелы по всему полю. заполняем оконтовку поля
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 0; j < columns; ++j)
			if (j == 0 || j == columns - 1)
				field[i] [j] = border_symbol;
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
	for (int j = 0; j < columns; ++j)
		field[(rows - 1)] [j] = border_symbol;

}