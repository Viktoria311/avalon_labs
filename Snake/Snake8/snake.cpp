#include "snake.h"
#include "const.h"
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

void move_snake(char**& field, 
				bool& game_on,
				const unsigned int& rows, 
				const unsigned int& columns,
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
	// перед шагом змейки запомним координаты хвоста!
	last_tail_x = snake_x[snake_size - 1];
	last_tail_y = snake_y[snake_size - 1];

	// выходим из функции , если невозможно сделать шаг
	if (snake_size != 1)
	{
		// запомнили координаты вспомогательные
		unsigned int last_x = snake_x[0];
		unsigned int last_y = snake_y[0];


		// рассматриваем невозможные варианты
		switch (direction)
		{
		case DIRECTION_LEFT:
		{
			// если голова и рядом стоящее тело с одинаковой y координатой
			// и змейка вовернута направо. То звейка не может повернуться
			if (snake_x[0] > snake_x[1] && snake_y[0] == snake_y[1] && snake_x[1] == snake_x[0] - 1)
			{
				return;
			}
			// если змейка идет налево и наступает на хвост
			else if ((snake_x[0] == 1 &&
					field[snake_y[0]][columns - 2] == tail_symbol) ||
					(snake_x[0] != 1 &&
					field[snake_y[0]][snake_x[0] - 1] == tail_symbol))
			{
				game_on = false;
				return;
			}
			else
			{
				// голова переместилась
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
			// если змейка идет направо и наступает на хвост
			else if ((snake_x[0] == columns - 2 &&
				field[snake_y[0]][1] == tail_symbol) ||
				(snake_x[0] != columns - 2 &&
					field[snake_y[0]][snake_x[0] + 1] == tail_symbol))
			{
				game_on = false;
				return;
			}
			else
			{
				// голова переместилась
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
			// если змейка идет наверх и наступает на хвост
			else if ((snake_y[0] == 1 &&
					field[snake_y[rows - 2]][snake_x[0]] == tail_symbol) ||
					(snake_y[0] != 1 &&
					field[snake_y[0] - 1][snake_x[0]] == tail_symbol))
			{
				game_on = false;
				return;
			}
			else
			{
				// голова переместилась
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
			// если змейка идет наверх и наступает на хвост
			else if ((snake_y[0] == rows - 2 &&
					field[1][snake_x[0]] == tail_symbol) ||
					(snake_y[0] != rows - 2 &&
					field[snake_y[0] + 1][snake_x[0]] == tail_symbol))
			{
				game_on = false;
				return;
			}
			else
			{
				// голова переместилась
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
		

		// двигаем оставшееся тело
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

	// если змейка съела еду bool check_eating()
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
					const unsigned int* const snake_x) // рядом ли элементы змейки друг к другу
{
	if (snake_x[0] < snake_x[snake_size - 1])
		for (int i = 0; i < snake_size - 1; ++i)
		{
			if (snake_x[i] != snake_x[i + 1] - 1)
				return false;
		}
	else // если индекс головы  больше индекса хвоста
		for (int i = 0; i < snake_size - 1; ++i)
		{
			if (snake_x[i] != snake_x[i + 1] + 1)
				return false;
		}
	return true;
}