#include "field.h"
#include "food.h"
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <iostream>

char field[columns] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }; // ������ �������� ����

void init_field()
{
	/*
	�	������� ���� ����������� �������� ������� (��������, �*�). 
	�	����� ������� clear_field();  
	*/
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	clear_field(); // ������� �� ����

	if (food_flag == true)
		field[food_x] = food_symbol;

	set_snake();
}

void print_field()
{
	/*
	�	������� ������  setCursorPosition().
	�	������ �������� ���� ��������� �� �����. 
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

void clear_field()
{
	/*
	������ �������� ���� ����������� ��������-������������ (��������, ��������). 
	*/
	for (int i = 1; i < columns - 1; ++i) // ������� �� ����� ����
		field[i] = field_symbol;
}