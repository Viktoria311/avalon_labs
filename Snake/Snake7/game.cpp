#include "game.h"
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"




void init_game(unsigned int* snake_x, unsigned int* snake_y)
{
	//��������� ��������� ������ ������
	snake_x[0] = 1; // 0 � column-1 ������
	snake_y[0] = 1;
}

void set_snake(char* field, 
				unsigned int snake_size,
				const unsigned int* const snake_x,
				const unsigned int* const snake_y)
{
	/*
	������ ��������������� � ������� ����, �.�.
	�	������ ������ ������ ���������� � ��������������� ������� �������� ����
	�	������� ������ ����� ���������� � ������� ����.
	*/
	field[snake_y[0] * columns + snake_x[0]] = head_symbol;

	for (int i = 1; i < snake_size; ++i)
		field[snake_y[i] * columns + snake_x[i]] = tail_symbol;
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

bool check_eating(unsigned int& snake_size, 
				const unsigned int* const snake_x, 
				const unsigned int* const snake_y,
				bool& food_flag, 
				const unsigned int& food_x, 
				const unsigned int& food_y)
{
	/*
	����������� �������� ����, ��� ������ ����� ���.
	���� ���������� ��� � ���������� ������ ������ ���������,
	��  ��������������� � false ������� ����, ��� ��� ���� �� ����.
	*/
	if (snake_x[0] == food_x && snake_y[0] == food_y)
	{
		food_flag = false;
		++snake_size; // ��������� ���� ���� �� 1
		return true;
	}

	else
	{
		food_flag = true;
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

void handle_cmd(const unsigned int& step, DIRECTION& direction)
{
	/*
	����������� ��������, ������� ��������� ���� [�������� ���-�� ���
	*/

	switch (step)
	{
	case LEFT:
		direction = DIRECTION_LEFT;
		break;
	case RIGHT:
		direction = DIRECTION_RIGHT;
		break;
	case TOP:
		direction = DIRECTION_TOP;
		break;
	case BOTTOM:
		direction = DIRECTION_BOTTOM;
		break;
	}
}
