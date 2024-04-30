#include "const.h"
#include "game.h"
#include "snake.h"
#include "field.h"
#include "food.h"

unsigned int timeout = 1000; // >100 (ms)

bool game_on = true;


void init_game()
{
	snake_x[0] = 3; // 0 � column-1 ������
}

void set_snake()
{
	/*
	������ ��������������� � ������� ����, �.�. 
	�	������ ������ ������ ���������� � ��������������� ������� �������� ����
	�	������� ������ ����� ���������� � ������� ����.
	*/
	field[snake_x[0]] = head_symbol;

	for (int i = 1; i < snake_size; ++i)
		field[snake_x[i]] = tail_symbol;
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

bool check_eating()
{
	/*
	����������� �������� ����, ��� ������ ����� ���.
	���� ���������� ��� � ���������� ������ ������ ���������, 
	��  ��������������� � false ������� ����, ��� ��� ���� �� ����.  
	*/
	if (snake_x[0] == food_x)
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

void handle_cmd(const unsigned int& step)
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
	}
}

