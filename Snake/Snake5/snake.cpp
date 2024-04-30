#include "snake.h"
#include "const.h"
#include "game.h"

unsigned int snake_size = 1;

DIRECTION direction = DIRECTION_RIGHT; // enum DIRECTION {};

unsigned int snake_x[L]; // = { 0 };  массив координат. индексы поля где есть змейка. индекс головы [0]. 

void init_snake()
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

void move_snake(const unsigned int& step)
{
	/*
	•	Передвигаются элементы хвоста
	•	В зависимости от направления движения голова змейки передвигается на 1 позицию.
	*/
	switch (direction)
	{
	case DIRECTION_LEFT:
	{
		// меняем голову и хвост местами, если надо
		// если позиция головы правее кончика хвоста, а шагать надо влево , 
		// И если ситуация *оо   Qо*
		if (snake_size > 1 &&
		  ((snake_x[0] > snake_x[snake_size - 1] && are_sequentially()) || // *   оооQ  *
		   (snake_x[0] < snake_x[snake_size - 1] && !are_sequentially())) ) // *ооQ   ооо* 
		{
			unsigned int helper;
			// changed places
			for (int i = 0; i < snake_size / 2; ++i)
			{
				helper = snake_x[i]; // меняем координаты головы и кончика хвоста  и остальных частей симметрично
				snake_x[i] = snake_x[snake_size - 1 - i];
				snake_x[snake_size - 1 - i] = helper;
			}
		}
		// шаг змейки
		for (int i = 0; i < snake_size; ++i) // меняем положение змейки на 1 назад
		{
			if (snake_x[i] == 1)
				snake_x[i] = columns - 2; // переводим позицию  в самый конец поля
			else
				--(snake_x[i]);
		}

		break;
	}
	case DIRECTION_RIGHT:
	{
		if (snake_size >= 1 &&
		   ((snake_x[0] < snake_x[snake_size - 1] && are_sequentially()) || // *   Qооо  *
			(snake_x[0] > snake_x[snake_size - 1] && !are_sequentially())) ) // *ооо   Qоо*  
		{
			unsigned int helper;
			// changed places
			for (int i = 0; i < snake_size / 2; ++i)
			{
				helper = snake_x[i]; // меняем координаты головы и кончика хвоста  и остальных частей симметрично
				snake_x[i] = snake_x[snake_size - 1 - i];
				snake_x[snake_size - 1 - i] = helper;
			}
		}

		// шаг змейки
		for (int i = 0; i < snake_size; ++i) // меняем положение змейки на 1 вперед
		{
			if (snake_x[i] == columns - 2)
				snake_x[i] = 1; // переводим позицию  в самое начало поля
			else
				++(snake_x[i]);
		}

		break;
	}
	default:
		//std::cout << "Eror" << std::endl;
		break;
	}
	
	if (check_eating()) // если змейка съела еду bool check_eating()
	{
		if (snake_size >= L)
			game_on = false;

		add_tail(step);
	}
}

void add_tail(const unsigned int& step)
{
	if (step == LEFT) // учитывать крайние случаи !!!
	{
		if (snake_x[snake_size - 2] + 1 == columns - 1) // если координата правее совпадает со стенкой справа
			snake_x[snake_size - 1] = 1;
		else
			snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1; // координата нового хвоста = координата правее на единицу прошлого хвоста
	}
	else // step == RIGHT
	{
		if (snake_x[snake_size - 2] - 1 == 0) // если координата хвоста слева совпадает со стенкой слева
			snake_x[snake_size - 1] = columns - 2;
		else
			snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1; // координата нового хвоста = координата левее на единицу прошлого хвоста
	}
}

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