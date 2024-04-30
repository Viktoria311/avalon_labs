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
				const unsigned int& food_y,
				const unsigned int& step,
				DIRECTION direction,
				unsigned int& snake_size,
				unsigned int* snake_x, 
				unsigned int* snake_y,
				unsigned int& last_tail_x,
				unsigned int& last_tail_y)
{
	// ����� ����� ������ �������� ���������� ������!
	last_tail_x = snake_x[snake_size - 1];
	last_tail_y = snake_y[snake_size - 1];

	// ������� �� ������� , ���� ���������� ������� ���
	if (snake_size != 1)
	{
		// ��������� ���������� ���������������
		unsigned int last_x = snake_x[0];
		unsigned int last_y = snake_y[0];


		// ������������� ����������� ��������
		switch (direction)
		{
		case DIRECTION_LEFT:
		{
			// ���� ������ � ����� ������� ���� � ���������� y �����������
			// � ������ ��������� �������. �� ������ �� ����� �����������
			if (snake_x[0] > snake_x[1] && snake_y[0] == snake_y[1] && snake_x[1] == snake_x[0] - 1)
			{
				return;
			}
			else
			{
				// ������ �������������
				if (snake_x[0] != 1)
					snake_x[0] = snake_x[0] - 1;
				else
					snake_x[0] = columns - 2;
			}
			break;
		}
		case DIRECTION_RIGHT:
		{
			if (snake_x[0] < snake_x[1] && snake_y[0] == snake_y[1] && snake_x[1] == snake_x[0] + 1)
			{
				return;
			}
			else
			{
				// ������ �������������
				if (snake_x[0] != columns - 2)
					snake_x[0] = snake_x[0] + 1;
				else
					snake_x[0] = 1;
			}
			break;
		}
		case DIRECTION_TOP:
		{
			if (snake_y[0] > snake_y[1] && snake_x[0] == snake_x[1] && snake_y[1] == snake_y[0] - 1)
			{
				return;
			}
			else
			{
				// ������ �������������
				if (snake_y[0] != 1)
					snake_y[0] = snake_y[0] - 1;
				else
					snake_y[0] = rows - 2;
			}
			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (snake_y[0] < snake_y[1] && snake_x[0] == snake_x[1] && snake_y[1] == snake_y[0] + 1)
			{
				return;
			}
			else
			{
				// ������ �������������
				if (snake_y[0] != rows - 2)
					snake_y[0] = snake_y[0] + 1;
				else
					snake_y[0] = 1;
			}
			break;
		}

		default:
			//std::cout << "Eror" << std::endl;
			break;
		}
		

		// ������� ���������� ����
		for (int i = 1; i < snake_size; ++i)
		{
			unsigned int x = snake_x[i];
			unsigned int y = snake_y[i];

			snake_x[i] = last_x;
			snake_y[i] = last_y;

			last_x = x;
			last_y = y;
		}
	}
	else
	{

		switch (direction)
		{
		case DIRECTION_LEFT:
		{
			if (snake_x[0] == 1)
				snake_x[0] = columns - 2;
			else
				snake_x[0] = snake_x[0] - 1;

			break;
		}
		case DIRECTION_RIGHT:
		{
			if (snake_x[0] == columns - 2)
				snake_x[0] = 1;
			else
				snake_x[0] = snake_x[0] + 1;

			break;
		}
		case DIRECTION_TOP:
		{
			if (snake_y[0] == 1)
				snake_y[0] = rows - 2;
			else
				snake_y[0] = snake_y[0] - 1;

			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (snake_y[0] == rows - 2)
				snake_y[0] = 1;
			else
				snake_y[0] = snake_y[0] + 1;

			break;
		}
		} // switch 
	}

	// ���� ������ ����� ��� bool check_eating()
	if (check_eating(snake_size, snake_x, snake_y, food_flag, food_x, food_y))
	{
		if (snake_size >= L)
			game_on = false;

		add_tail(step, snake_size, snake_x, snake_y, last_tail_x, last_tail_y);
	}
}

void add_tail(const unsigned int& step,
		unsigned int snake_size,
		unsigned int* snake_x,
		unsigned int* snake_y,
		const unsigned int& last_tail_x,
		const unsigned int& last_tail_y)
{
	snake_x[snake_size - 1] = last_tail_x;
	snake_y[snake_size - 1] = last_tail_y;
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