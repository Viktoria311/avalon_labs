#include "snake.h"
#include "const.h"
#include "field.h"
#include "food.h"
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

void move_snake(Game& my_game, 
				field& my_field,
				food& my_food,
				const unsigned int& step,
				snake& my_snake,
				unsigned int& last_tail_x,
				unsigned int& last_tail_y)
{
	// ����� ����� ������ �������� ���������� ������!
	last_tail_x = my_snake.snake_x[my_snake.snake_size - 1];
	last_tail_y = my_snake.snake_y[my_snake.snake_size - 1];

	// ������� �� ������� , ���� ���������� ������� ���
	if (my_snake.snake_size != 1)
	{
		// ��������� ���������� ���������������
		unsigned int last_x = my_snake.snake_x[0];
		unsigned int last_y = my_snake.snake_y[0];


		// ������������� ����������� ��������
		switch (my_snake.direction)
		{
		case DIRECTION_LEFT:
		{
			// ���� ������ � ����� ������� ���� � ���������� y �����������
			// � ������ ��������� �������. �� ������ �� ����� �����������
			if (my_snake.snake_x[0] > my_snake.snake_x[1] && my_snake.snake_y[0] == my_snake.snake_y[1] && 
				my_snake.snake_x[1] == my_snake.snake_x[0] - 1)
			{
				return;
			}
			// ���� ������ ���� ������ � ��������� �� �����
			else if ((my_snake.snake_x[0] == 1 &&
				my_field.Field[my_snake.snake_y[0]][my_field.columns - 2] == tail_symbol) ||
				(my_snake.snake_x[0] != 1 &&
					my_field.Field[my_snake.snake_y[0]][my_snake.snake_x[0] - 1] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// ������ �������������
				if (my_snake.snake_x[0] != 1)
					my_snake.snake_x[0] = my_snake.snake_x[0] - 1;
				else
					my_snake.snake_x[0] = my_field.columns - 2;
			}
			break;
		}
		case DIRECTION_RIGHT:
		{
			if (my_snake.snake_x[0] < my_snake.snake_x[1] && my_snake.snake_y[0] == my_snake.snake_y[1] &&
				my_snake.snake_x[1] == my_snake.snake_x[0] + 1)
			{
				return;
			}
			// ���� ������ ���� ������� � ��������� �� �����
			else if ((my_snake.snake_x[0] == my_field.columns - 2 &&
					my_field.Field[my_snake.snake_y[0]][1] == tail_symbol) ||
					(my_snake.snake_x[0] != my_field.columns - 2 &&
					my_field.Field[my_snake.snake_y[0]][my_snake.snake_x[0] + 1] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// ������ �������������
				if (my_snake.snake_x[0] != my_field.columns - 2)
					my_snake.snake_x[0] = my_snake.snake_x[0] + 1;
				else
					my_snake.snake_x[0] = 1;
			}
			break;
		}
		case DIRECTION_TOP:
		{
			if (my_snake.snake_y[0] > my_snake.snake_y[1] && my_snake.snake_x[0] == my_snake.snake_x[1] && 
				my_snake.snake_y[1] == my_snake.snake_y[0] - 1)
			{
				return;
			}
			// ���� ������ ���� ������ � ��������� �� �����
			else if ((my_snake.snake_y[0] == 1 &&
				my_field.Field[my_snake.snake_y[my_field.rows - 2]][my_snake.snake_x[0]] == tail_symbol) ||
				(my_snake.snake_y[0] != 1 &&
					my_field.Field[my_snake.snake_y[0] - 1][my_snake.snake_x[0]] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// ������ �������������
				if (my_snake.snake_y[0] != 1)
					my_snake.snake_y[0] = my_snake.snake_y[0] - 1;
				else
					my_snake.snake_y[0] = my_field.rows - 2;
			}
			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (my_snake.snake_y[0] < my_snake.snake_y[1] && my_snake.snake_x[0] == my_snake.snake_x[1] && 
				my_snake.snake_y[1] == my_snake.snake_y[0] + 1)
			{
				return;
			}
			// ���� ������ ���� ������ � ��������� �� �����
			else if ((my_snake.snake_y[0] == my_field.rows - 2 &&
					my_field.Field[1][my_snake.snake_x[0]] == tail_symbol) ||
					(my_snake.snake_y[0] != my_field.rows - 2 &&
					my_field.Field[my_snake.snake_y[0] + 1][my_snake.snake_x[0]] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// ������ �������������
				if (my_snake.snake_y[0] != my_field.rows - 2)
					my_snake.snake_y[0] = my_snake.snake_y[0] + 1;
				else
					my_snake.snake_y[0] = 1;
			}
			break;
		}

		default:
			//std::cout << "Eror" << std::endl;
			break;
		}
		

		// ������� ���������� ����
		for (int i = 1; i < my_snake.snake_size; ++i)
		{
			unsigned int x = my_snake.snake_x[i];
			unsigned int y = my_snake.snake_y[i];

			my_snake.snake_x[i] = last_x;
			my_snake.snake_y[i] = last_y;

			last_x = x;
			last_y = y;
		}
	}
	else
	{

		switch (my_snake.direction)
		{
		case DIRECTION_LEFT:
		{
			if (my_snake.snake_x[0] == 1)
				my_snake.snake_x[0] = my_field.columns - 2;
			else
				my_snake.snake_x[0] = my_snake.snake_x[0] - 1;

			break;
		}
		case DIRECTION_RIGHT:
		{
			if (my_snake.snake_x[0] == my_field.columns - 2)
				my_snake.snake_x[0] = 1;
			else
				my_snake.snake_x[0] = my_snake.snake_x[0] + 1;

			break;
		}
		case DIRECTION_TOP:
		{
			if (my_snake.snake_y[0] == 1)
				my_snake.snake_y[0] = my_field.rows - 2;
			else
				my_snake.snake_y[0] = my_snake.snake_y[0] - 1;

			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (my_snake.snake_y[0] == my_field.rows - 2)
				my_snake.snake_y[0] = 1;
			else
				my_snake.snake_y[0] = my_snake.snake_y[0] + 1;

			break;
		}
		} // switch 
	}

	// ���� ������ ����� ��� bool check_eating()
	if (check_eating(my_snake, my_food))
	{
		if (my_snake.snake_size >= L)
			my_game.game_on = false;

		add_tail(step, my_snake, last_tail_x, last_tail_y);
	}
}

void add_tail(const unsigned int& step,
		snake& my_snake,
		const unsigned int& last_tail_x,
		const unsigned int& last_tail_y)
{
	my_snake.snake_x[my_snake.snake_size - 1] = last_tail_x;
	my_snake.snake_y[my_snake.snake_size - 1] = last_tail_y;
}


bool are_sequentially(snake& my_snake) // ����� �� �������� ������ ���� � �����
{
	if (my_snake.snake_x[0] < my_snake.snake_x[my_snake.snake_size - 1])
		for (int i = 0; i < my_snake.snake_size - 1; ++i)
		{
			if (my_snake.snake_x[i] != my_snake.snake_x[i + 1] - 1)
				return false;
		}
	else // ���� ������ ������  ������ ������� ������
		for (int i = 0; i < my_snake.snake_size - 1; ++i)
		{
			if (my_snake.snake_x[i] != my_snake.snake_x[i + 1] + 1)
				return false;
		}
	return true;
}