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
			unsigned int& food_x)
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
			food_x = rand() % (columns - 1);
		} while (field[food_x] != ' ');

		field[food_x] = food_symbol;

		food_flag = true;
	}

}