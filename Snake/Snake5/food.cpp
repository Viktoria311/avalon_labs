#include "food.h"
#include "field.h"
#include "const.h"
#include "game.h"
#include <cstdlib>
#include <ctime>

bool food_flag = false;

unsigned int food_x;

void init_food()
{
	/*
	Устанавливаются начальные значения для параметров еды.
	*/
	// чем начальное значение отличается от случайной генерации?

}

void generate_food()
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