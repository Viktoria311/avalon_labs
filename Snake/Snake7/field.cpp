#include "field.h"
#include "food.h"
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <iostream>



void init_field(char* field, 
				//bool& game_on,
				bool food_flag,
				unsigned int& food_x, 
				unsigned int& food_y,
				unsigned int snake_size, 
				const unsigned int* snake_x, 
				const unsigned int* snake_y)
{
	/*
	�	������� ���� ����������� �������� ������� (��������, �*�).
	�	����� ������� clear_field();
	*/

	init_borders(field);// �����
	clear_field(field); // ������� �� ����
	
	set_snake(field, snake_size, snake_x, snake_y);

	if (food_flag == true)
		field[food_y * columns + food_x] = food_symbol;
	//generate_food(field, game_on, food_flag, food_x, food_y); // �����, ������������� ��� ������
}

void print_field(const char* field)
{
	/*
	�	������� ������  setCursorPosition().
	�	������ �������� ���� ��������� �� �����.
	*/
	setCursorPosition(0, 0);
	// ����
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
	// �����
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			std::cout << field[i * columns + j];

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void clear_field(char* field)
{
	/*
	������ �������� ���� ����������� ��������-������������ (��������, ��������).
	*/
	// ����
	//for (int i = 1; i < columns - 1; ++i) // ������� �� ����� ����
	//	field[i] = field_symbol;

	// �����



	//  ������� �� ����� ����. ��������� ��������� ����
	for (int i = 1; i < rows - 1; ++i) 
	{
		for (int j = 1; j < columns - 1; ++j)
			//if (j != 0 && j != columns - 1)
				field[i * columns + j] = field_symbol;// ����� ������� ������ * columns + ����� �������� �������

	}

}

void init_borders(char* field)
{
	// ��������� ���� ���� ������ 
	for (int j = 0; j < columns; ++j)
		field[0 * columns + j] = border_symbol;
	///*
	//  ������� �� ����� ����. ��������� ��������� ����
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 0; j < columns; ++j)
			if (j == 0 || j == columns - 1)
				field[i * columns + j] = border_symbol;
	}
	//*/
	/*
	��� ���  ��������� ����� � ������ ��-�����������
	for (int i = 1; i < rows - 1; ++i)
		field[i * columns] = border_symbol;

	for (int i = 1; i < rows - 1; ++i)
		field[i * columns + columns - 1] = border_symbol;
	*/

	// ��������� ���� ���� �����
	for (int j = 0; j < columns; ++j)
		field[(rows - 1) * columns + j] = border_symbol;

}