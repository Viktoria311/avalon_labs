#include "snake.h"
#include "const.h"

unsigned int snake_size = 1;

DIRECTION direction = DIRECTION_RIGHT; // enum DIRECTION {};

unsigned int snake_x[L] = { 0 }; // массив координат. индексы поля где есть змейка. индекс головы [0]. 

bool are_sequentially() // рядом ли элементы змейки друг к другу
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