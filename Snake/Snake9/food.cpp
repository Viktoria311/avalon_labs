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
generate_food(field& my_field,
			Game& my_game,
			food& my_food)
{
	/*
	Генерируется случайное значение, которое используется в качестве координаты еды в поле игры.
	Важно, чтобы позиция еды попадала в индексов игрового поля, но в то же время не попадала на границу поля.
	*/
	if (my_game.game_on && my_food.food_flag == false)// установить еду рандомно food_x - координата еды
	{
		srand(time(0));

		do
		{
			// генерируем координаты еды
			my_food.food_x = rand() % (my_field.columns - 1);
			my_food.food_y = rand() % (my_field.rows - 1);

			// повторяем, пока получившаяся точка на поле не будет пустой
			// можем попасть либо в змейку,либо в рамку
		} while (my_field.Field[my_food.food_y ] [my_food.food_x] != ' ');

		my_field.Field[my_food.food_y ] [my_food.food_x] = food_symbol;

		my_food.food_flag = true;
	}

}