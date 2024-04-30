#include "snake.h"
#include "const.h"
#include "field.h"
#include "food.h"
#include "game.h"


void init_snake(unsigned int& snake_size, unsigned int* snake_x)
{
	/*
	•	Устанавливается начальный размер змейки.
	•	Массив змейки заполняется значениями
Если размер змейки равен 1 (имеется только голова), то заполнение массива очевидно. А если змейка кроме головы имеет еще хвост, то нужно немного подумать.
А еще было бы интересно заполнять массив змейки по-разному, в зависимости от направления ее движения.
	*/
	snake_size = 1;
	for (int i = 0; i < snake_size; ++i)
		snake_x[i] = 3;
}

void move_snake(Game& my_game,
				const unsigned int& step)
{
	// перед шагом змейки запомним координаты хвоста!
	// предыдущее положение кончика хвоста по оси x
	unsigned int last_tail_x = my_game.my_snake.snake_x[my_game.my_snake.snake_size - 1];
	// предыдущее положение кончика хвоста по оси y
	unsigned int last_tail_y = my_game.my_snake.snake_y[my_game.my_snake.snake_size - 1];

	// выходим из функции , если невозможно сделать шаг
	if (my_game.my_snake.snake_size != 1)
	{
		// запомнили координаты вспомогательные
		unsigned int last_x = my_game.my_snake.snake_x[0];
		unsigned int last_y = my_game.my_snake.snake_y[0];


		// рассматриваем невозможные варианты
		switch (my_game.my_snake.direction)
		{
		case DIRECTION_LEFT:
		{
			// если голова и рядом стоящее тело с одинаковой y координатой
			// и змейка вовернута направо. То звейка не может повернуться
			if (my_game.my_snake.snake_x[0] > my_game.my_snake.snake_x[1] && 
				my_game.my_snake.snake_y[0] == my_game.my_snake.snake_y[1] &&
				my_game.my_snake.snake_x[1] == my_game.my_snake.snake_x[0] - 1)
			{
				return;
			}
			// если змейка идет налево и наступает на хвост
			else if ((my_game.my_snake.snake_x[0] == 1 && 
					my_game.my_field.Field[my_game.my_snake.snake_y[0]][my_game.my_field.columns - 2] == tail_symbol) ||
					(my_game.my_snake.snake_x[0] != 1 && 
					my_game.my_field.Field[my_game.my_snake.snake_y[0]][my_game.my_snake.snake_x[0] - 1] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// голова переместилась
				if (my_game.my_snake.snake_x[0] != 1)
					my_game.my_snake.snake_x[0] = my_game.my_snake.snake_x[0] - 1;
				else
					my_game.my_snake.snake_x[0] = my_game.my_field.columns - 2;
			}
			break;
		}
		case DIRECTION_RIGHT:
		{
			if (my_game.my_snake.snake_x[0] < my_game.my_snake.snake_x[1] && 
				my_game.my_snake.snake_y[0] == my_game.my_snake.snake_y[1] &&
				my_game.my_snake.snake_x[1] == my_game.my_snake.snake_x[0] + 1)
			{
				return;
			}
			// если змейка идет направо и наступает на хвост
			else if ((my_game.my_snake.snake_x[0] == my_game.my_field.columns - 2 &&
				my_game.my_field.Field[my_game.my_snake.snake_y[0]][ 1 ] == tail_symbol) ||
				(my_game.my_snake.snake_x[0] != my_game.my_field.columns - 2 &&
					my_game.my_field.Field[my_game.my_snake.snake_y[0]][my_game.my_snake.snake_x[0] + 1] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// голова переместилась
				if (my_game.my_snake.snake_x[0] != my_game.my_field.columns - 2)
					my_game.my_snake.snake_x[0] = my_game.my_snake.snake_x[0] + 1;
				else
					my_game.my_snake.snake_x[0] = 1;
			}
			break;
		}
		case DIRECTION_TOP:
		{
			if (my_game.my_snake.snake_y[0] > my_game.my_snake.snake_y[1] && 
				my_game.my_snake.snake_x[0] == my_game.my_snake.snake_x[1] &&
				my_game.my_snake.snake_y[1] == my_game.my_snake.snake_y[0] - 1)
			{
				return;
			}
			// если змейка идет наверх и наступает на хвост
			else if ((my_game.my_snake.snake_y[0] == 1 &&
				my_game.my_field.Field[my_game.my_snake.snake_y[my_game.my_field.rows - 2]][my_game.my_snake.snake_x[0]] == tail_symbol) ||
				(my_game.my_snake.snake_y[0] != 1 &&
					my_game.my_field.Field[my_game.my_snake.snake_y[0] - 1][my_game.my_snake.snake_x[0]] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// голова переместилась
				if (my_game.my_snake.snake_y[0] != 1)
					my_game.my_snake.snake_y[0] = my_game.my_snake.snake_y[0] - 1;
				else
					my_game.my_snake.snake_y[0] = my_game.my_field.rows - 2;
			}
			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (my_game.my_snake.snake_y[0] < my_game.my_snake.snake_y[1] && 
				my_game.my_snake.snake_x[0] == my_game.my_snake.snake_x[1] &&
				my_game.my_snake.snake_y[1] == my_game.my_snake.snake_y[0] + 1)
			{
				return;
			}
			// если змейка идет наверх и наступает на хвост
			else if ((my_game.my_snake.snake_y[0] == my_game.my_field.rows - 2 &&
				my_game.my_field.Field[ 1 ][my_game.my_snake.snake_x[0]] == tail_symbol) ||
				(my_game.my_snake.snake_y[0] != my_game.my_field.rows - 2 &&
					my_game.my_field.Field[my_game.my_snake.snake_y[0] + 1][my_game.my_snake.snake_x[0]] == tail_symbol))
			{
				my_game.game_on = false;
				return;
			}
			else
			{
				// голова переместилась
				if (my_game.my_snake.snake_y[0] != my_game.my_field.rows - 2)
					my_game.my_snake.snake_y[0] = my_game.my_snake.snake_y[0] + 1;
				else
					my_game.my_snake.snake_y[0] = 1;
			}
			break;
		}

		default:
			//std::cout << "Eror" << std::endl;
			break;
		}
		

		// двигаем оставшееся тело
		for (int i = 1; i < my_game.my_snake.snake_size; ++i)
		{
			unsigned int x = my_game.my_snake.snake_x[i];
			unsigned int y = my_game.my_snake.snake_y[i];

			my_game.my_snake.snake_x[i] = last_x;
			my_game.my_snake.snake_y[i] = last_y;

			last_x = x;
			last_y = y;
		}
	}
	else
	{

		switch (my_game.my_snake.direction)
		{
		case DIRECTION_LEFT:
		{
			if (my_game.my_snake.snake_x[0] == 1)
				my_game.my_snake.snake_x[0] = my_game.my_field.columns - 2;
			else
				my_game.my_snake.snake_x[0] = my_game.my_snake.snake_x[0] - 1;

			break;
		}
		case DIRECTION_RIGHT:
		{
			if (my_game.my_snake.snake_x[0] == my_game.my_field.columns - 2)
				my_game.my_snake.snake_x[0] = 1;
			else
				my_game.my_snake.snake_x[0] = my_game.my_snake.snake_x[0] + 1;

			break;
		}
		case DIRECTION_TOP:
		{
			if (my_game.my_snake.snake_y[0] == 1)
				my_game.my_snake.snake_y[0] = my_game.my_field.rows - 2;
			else
				my_game.my_snake.snake_y[0] = my_game.my_snake.snake_y[0] - 1;

			break;
		}
		case DIRECTION_BOTTOM:
		{
			if (my_game.my_snake.snake_y[0] == my_game.my_field.rows - 2)
				my_game.my_snake.snake_y[0] = 1;
			else
				my_game.my_snake.snake_y[0] = my_game.my_snake.snake_y[0] + 1;

			break;
		}
		} // switch 
	}

	// если змейка съела еду bool check_eating()
	if (check_eating(my_game))
	{
		if (my_game.my_snake.snake_size >= L)
			my_game.game_on = false;

		add_tail(step, my_game, last_tail_x, last_tail_y);
	}
}

void add_tail(const unsigned int& step,
			Game& my_game,
			const unsigned int& last_tail_x,
			const unsigned int& last_tail_y)
{
	my_game.my_snake.snake_x[my_game.my_snake.snake_size - 1] = last_tail_x;
	my_game.my_snake.snake_y[my_game.my_snake.snake_size - 1] = last_tail_y;
}


bool are_sequentially(snake& my_snake) // рядом ли элементы змейки друг к другу
{
	if (my_snake.snake_x[0] < my_snake.snake_x[my_snake.snake_size - 1])
		for (int i = 0; i < my_snake.snake_size - 1; ++i)
		{
			if (my_snake.snake_x[i] != my_snake.snake_x[i + 1] - 1)
				return false;
		}
	else // если индекс головы  больше индекса хвоста
		for (int i = 0; i < my_snake.snake_size - 1; ++i)
		{
			if (my_snake.snake_x[i] != my_snake.snake_x[i + 1] + 1)
				return false;
		}
	return true;
}