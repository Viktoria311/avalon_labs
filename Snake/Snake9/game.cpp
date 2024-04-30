#include "game.h"
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"




void init_game(snake& my_snake)
{
	//��������� ��������� ������ ������
	my_snake.snake_x[0] = 1; // 0 � column-1 ������
	my_snake.snake_y[0] = 1;
}

void set_snake(field& my_field,
				snake& my_snake)
{
	/*
	������ ��������������� � ������� ����, �.�.
	�	������ ������ ������ ���������� � ��������������� ������� �������� ����
	�	������� ������ ����� ���������� � ������� ����.
	*/
	//field[snake_y[0] * columns + snake_x[0]] = head_symbol;
	my_field.Field[my_snake.snake_y[0] ][my_snake.snake_x[0] ] = head_symbol;

	for (int i = 1; i < my_snake.snake_size; ++i)
		my_field.Field[my_snake.snake_y[i] ][my_snake.snake_x[i] ] = tail_symbol;
}

void set_food()
{
	/*
	��� ��������������� � ������� ����.  ����� �������� ������� generate_food() � ���������, ��� � ��������������� ������� ������ ���.
	*/
	// ����� �������� ��� ���� �������
}

void check_game()
{
	/*
	���������, ��� ������ �������� ������ ������������� �������
	*/

}

void check_snake()
{
	/*
	����������� �������� ����, ��� ������ ����������� � �������� ����.
	� ����������� �� ����������� �������� ������ ����� ����������� ��� � ������, ��� � � ����� �������� ���� ����.

	�����!
	�	���� ������ ������ ��������� � ������, �� �������� ������ ���� �� ������,
	�.�.  ��� ���������� � ������� (����������������) ���� ����.
	*/


}

bool check_eating(snake& my_snake,
					food& my_food)
{
	/*
	����������� �������� ����, ��� ������ ����� ���.
	���� ���������� ��� � ���������� ������ ������ ���������,
	��  ��������������� � false ������� ����, ��� ��� ���� �� ����.
	*/
	if (my_snake.snake_x[0] == my_food.food_x && my_snake.snake_y[0] == my_food.food_y)
	{
		my_food.food_flag = false;
		++my_snake.snake_size; // ��������� ���� ���� �� 1
		return true;
	}

	else
	{
		my_food.food_flag = true;
		return false;
	}
}

void clear_snake()
{
	/*
	��������� ������� ������ � �������, �.�. � ��������������� ������� ���� ��������������� ������-����������� ����.
	*/
	// ��������, ����� ���� ������, ���� ���� �� ����� � �� �����������, �� ���� ���������� ���������� ������� ������

}

void handle_cmd(const unsigned int& step, snake& my_snake)
{
	/*
	����������� ��������, ������� ��������� ���� [�������� ���-�� ���
	*/

	switch (step)
	{
	case LEFT:
		my_snake.direction = DIRECTION_LEFT;
		break;
	case RIGHT:
		my_snake.direction = DIRECTION_RIGHT;
		break;
	case TOP:
		my_snake.direction = DIRECTION_TOP;
		break;
	case BOTTOM:
		my_snake.direction = DIRECTION_BOTTOM;
		break;
	}
}
