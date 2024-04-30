#include "food.h"
#include "field.h"
#include "const.h"
#include "game.h"
#include <cstdlib>
#include <ctime>



void init_food()
{
	/*
	Устанавливаются начальные значения для параметров еды.
	*/
	// чем начальное значение отличается от случайной генерации?

}

void 
generate_food(char* field, 
			bool game_on,
			bool& food_flag, 
			unsigned int& food_x,
			unsigned int& food_y)
{
	/*
	Генерируется случайное значение, которое используется в качестве координаты еды в поле игры.
	Важно, чтобы позиция еды попадала в индексов игрового поля, но в то же время не попадала на границу поля.
	*/
	if (game_on && food_flag == false)// установить еду рандомно food_x - координата еды
	{
		srand(time(0));

		do
		{
			// генерируем координаты еды
			food_x = rand() % (columns - 1);
			food_y = rand() % (rows - 1);

			// повторяем, пока получившаяся точка на поле не будет пустой
			// можем попасть либо в змейку,либо в рамку
		} while (field[food_y * columns + food_x] != ' ');

		field[food_y * columns + food_x] = food_symbol;

		food_flag = true;
	}

}