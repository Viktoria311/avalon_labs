#include "snake.h"
#include "const.h"
#include "game.h"

unsigned int snake_size = 1;

DIRECTION direction = DIRECTION_RIGHT; // enum DIRECTION {};

unsigned int snake_x[L]; // = { 0 };  ������ ���������. ������� ���� ��� ���� ������. ������ ������ [0]. 

void init_snake()
{
	/*
	�	��������������� ��������� ������ ������. 
	�	������ ������ ����������� ����������
���� ������ ������ ����� 1 (������� ������ ������), �� ���������� ������� ��������. � ���� ������ ����� ������ ����� ��� �����, �� ����� ������� ��������.
� ��� ���� �� ��������� ��������� ������ ������ ��-�������, � ����������� �� ����������� �� ��������.
	*/
	snake_size = 1;
	for (int i = 0; i < snake_size; ++i)
		snake_x[i] = 3;
}

void move_snake(const unsigned int& step)
{
	/*
	�	������������� �������� ������
	�	� ����������� �� ����������� �������� ������ ������ ������������� �� 1 �������.
	*/
	switch (direction)
	{
	case DIRECTION_LEFT:
	{
		// ������ ������ � ����� �������, ���� ����
		// ���� ������� ������ ������ ������� ������, � ������ ���� ����� , 
		// � ���� �������� *��   Q�*
		if (snake_size > 1 &&
		  ((snake_x[0] > snake_x[snake_size - 1] && are_sequentially()) || // *   ���Q  *
		   (snake_x[0] < snake_x[snake_size - 1] && !are_sequentially())) ) // *��Q   ���* 
		{
			unsigned int helper;
			// changed places
			for (int i = 0; i < snake_size / 2; ++i)
			{
				helper = snake_x[i]; // ������ ���������� ������ � ������� ������  � ��������� ������ �����������
				snake_x[i] = snake_x[snake_size - 1 - i];
				snake_x[snake_size - 1 - i] = helper;
			}
		}
		// ��� ������
		for (int i = 0; i < snake_size; ++i) // ������ ��������� ������ �� 1 �����
		{
			if (snake_x[i] == 1)
				snake_x[i] = columns - 2; // ��������� �������  � ����� ����� ����
			else
				--(snake_x[i]);
		}

		break;
	}
	case DIRECTION_RIGHT:
	{
		if (snake_size >= 1 &&
		   ((snake_x[0] < snake_x[snake_size - 1] && are_sequentially()) || // *   Q���  *
			(snake_x[0] > snake_x[snake_size - 1] && !are_sequentially())) ) // *���   Q��*  
		{
			unsigned int helper;
			// changed places
			for (int i = 0; i < snake_size / 2; ++i)
			{
				helper = snake_x[i]; // ������ ���������� ������ � ������� ������  � ��������� ������ �����������
				snake_x[i] = snake_x[snake_size - 1 - i];
				snake_x[snake_size - 1 - i] = helper;
			}
		}

		// ��� ������
		for (int i = 0; i < snake_size; ++i) // ������ ��������� ������ �� 1 ������
		{
			if (snake_x[i] == columns - 2)
				snake_x[i] = 1; // ��������� �������  � ����� ������ ����
			else
				++(snake_x[i]);
		}

		break;
	}
	default:
		//std::cout << "Eror" << std::endl;
		break;
	}
	
	if (check_eating()) // ���� ������ ����� ��� bool check_eating()
	{
		if (snake_size >= L)
			game_on = false;

		add_tail(step);
	}
}

void add_tail(const unsigned int& step)
{
	if (step == LEFT) // ��������� ������� ������ !!!
	{
		if (snake_x[snake_size - 2] + 1 == columns - 1) // ���� ���������� ������ ��������� �� ������� ������
			snake_x[snake_size - 1] = 1;
		else
			snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1; // ���������� ������ ������ = ���������� ������ �� ������� �������� ������
	}
	else // step == RIGHT
	{
		if (snake_x[snake_size - 2] - 1 == 0) // ���� ���������� ������ ����� ��������� �� ������� �����
			snake_x[snake_size - 1] = columns - 2;
		else
			snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1; // ���������� ������ ������ = ���������� ����� �� ������� �������� ������
	}
}

bool are_sequentially() // ����� �� �������� ������ ���� � �����
{
	if (snake_x[0] < snake_x[snake_size - 1])
		for (int i = 0; i < snake_size - 1; ++i)
		{
			if (snake_x[i] != snake_x[i + 1] - 1)
				return false;
		}
	else // ���� ������ ������  ������ ������� ������
		for (int i = 0; i < snake_size - 1; ++i)
		{
			if (snake_x[i] != snake_x[i + 1] + 1)
				return false;
		}
	return true;
}