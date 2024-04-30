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
generate_food(field& my_field,
			Game& my_game,
			food& my_food)
{
	/*
	������������ ��������� ��������, ������� ������������ � �������� ���������� ��� � ���� ����.
	�����, ����� ������� ��� �������� � �������� �������� ����, �� � �� �� ����� �� �������� �� ������� ����.
	*/
	if (my_game.game_on && my_food.food_flag == false)// ���������� ��� �������� food_x - ���������� ���
	{
		srand(time(0));

		do
		{
			// ���������� ���������� ���
			my_food.food_x = rand() % (my_field.columns - 1);
			my_food.food_y = rand() % (my_field.rows - 1);

			// ���������, ���� ������������ ����� �� ���� �� ����� ������
			// ����� ������� ���� � ������,���� � �����
		} while (my_field.Field[my_food.food_y ] [my_food.food_x] != ' ');

		my_field.Field[my_food.food_y ] [my_food.food_x] = food_symbol;

		my_food.food_flag = true;
	}

}