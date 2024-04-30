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
generate_food(Game& my_game)
{
	/*
	������������ ��������� ��������, ������� ������������ � �������� ���������� ��� � ���� ����.
	�����, ����� ������� ��� �������� � �������� �������� ����, �� � �� �� ����� �� �������� �� ������� ����.
	*/
	if (my_game.game_on && my_game.my_food.food_flag == false)// ���������� ��� �������� food_x - ���������� ���
	{
		srand(time(0));

		do
		{
			// ���������� ���������� ���
			my_game.my_food.food_x = rand() % (my_game.my_field.columns - 1);
			my_game.my_food.food_y = rand() % (my_game.my_field.rows - 1);

			// ���������, ���� ������������ ����� �� ���� �� ����� ������
			// ����� ������� ���� � ������,���� � �����
		} while (my_game.my_field.Field[my_game.my_food.food_y ] [my_game.my_food.food_x] != ' ');

		my_game.my_field.Field[my_game.my_food.food_y ] [my_game.my_food.food_x] = food_symbol;

		my_game.my_food.food_flag = true;
	}

}