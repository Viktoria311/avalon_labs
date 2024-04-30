#include "snake.h"
#include "const.h"
#include "game.h"



void init_snake(unsigned int& snake_size, unsigned int* snake_x)
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

void move_snake(bool& game_on, 
				bool& food_flag, 
				const unsigned int& food_x,
				const unsigned int& step,
				DIRECTION direction,
				unsigned int& snake_size,
				unsigned int* snake_x)
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
			((snake_x[0] > snake_x[snake_size - 1] && are_sequentially(snake_size, snake_x)) || // *   ���Q  *
				(snake_x[0] < snake_x[snake_size - 1] && !are_sequentially(snake_size, snake_x)))) // *��Q   ���* 
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
			((snake_x[0] < snake_x[snake_size - 1] && are_sequentially(snake_size, snake_x)) || // *   Q���  *
				(snake_x[0] > snake_x[snake_size - 1] && !are_sequentially(snake_size, snake_x)))) // *���   Q��*  
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

	if (check_eating(snake_size, snake_x, food_flag, food_x)) // ���� ������ ����� ��� bool check_eating()
	{
		if (snake_size >= L)
			game_on = false;

		add_tail(step, snake_size, snake_x);
	}
}

void add_tail(const unsigned int& step, 
			unsigned int snake_size,
			unsigned int* snake_x)
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

bool are_sequentially(unsigned int snake_size,
					const unsigned int* const snake_x) // ����� �� �������� ������ ���� � �����
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