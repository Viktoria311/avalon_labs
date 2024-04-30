#include "food.h"
#include "field.h"
#include "const.h"
#include "game.h"
#include <cstdlib>
#include <ctime>



void init_food()
{
	/*
	��������������� ��������� �������� ��� ���������� ���.
	*/
	// ��� ��������� �������� ���������� �� ��������� ���������?

}

void 
generate_food(char* field, 
			bool game_on,
			bool& food_flag, 
			unsigned int& food_x,
			unsigned int& food_y)
{
	/*
	������������ ��������� ��������, ������� ������������ � �������� ���������� ��� � ���� ����.
	�����, ����� ������� ��� �������� � �������� �������� ����, �� � �� �� ����� �� �������� �� ������� ����.
	*/
	if (game_on && food_flag == false)// ���������� ��� �������� food_x - ���������� ���
	{
		srand(time(0));

		do
		{
			// ���������� ���������� ���
			food_x = rand() % (columns - 1);
			food_y = rand() % (rows - 1);

			// ���������, ���� ������������ ����� �� ���� �� ����� ������
			// ����� ������� ���� � ������,���� � �����
		} while (field[food_y * columns + food_x] != ' ');

		field[food_y * columns + food_x] = food_symbol;

		food_flag = true;
	}

}