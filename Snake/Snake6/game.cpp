#include "game.h"
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"




void init_game(unsigned int* snake_x)
{
	snake_x[0] = 3; // 0 и column-1 нельзя
}

void set_snake(char* field, 
				unsigned int snake_size,
				const unsigned int* const snake_x)
{
	/*
	Змейка устанавливается в игровом поле, т.е.
	•	символ головы змейки копируется в соответствующую позицию игрового поля
	•	символы хвоста также копируются в игровое поле.
	*/
	field[snake_x[0]] = head_symbol;

	for (int i = 1; i < snake_size; ++i)
		field[snake_x[i]] = tail_symbol;
}

void set_food()
{
	/*
	Еда устанавливается в игровом поле.  Можно вызывать функцию generate_food() и проверять, что в сгенерированной позиции ничего нет.
	*/
	// можно обойтись без этой функции
}

void check_game()
{
	/*
	Проверяем, что змейка достигла своего максимального размера
	*/

}

void check_snake()
{
	/*
	Выполняется проверка того, что змейка встретилась с границей поля.
	В зависимости от направления движения змейка может встретиться как с правой, так и с левой границей поля игры.

	Важно!
	•	Если голова змейки упирается в стенку, то движение змейки идет по кольцу,
	т.е.  она появляется с другого (противоположного) края поля.
	*/


}

bool check_eating(unsigned int& snake_size, 
				const unsigned int* const snake_x, 
				bool& food_flag, 
				const unsigned int& food_x)
{
	/*
	Выполняется проверка того, что змейка съела еду.
	Если координаты еды и координаты головы змейки совпадают,
	то  устанавливается в false признак того, что еда есть на поле.
	*/
	if (snake_x[0] == food_x)
	{
		food_flag = false;
		++snake_size; // увеличить тело змеи на 1
		return true;
	}

	else
	{
		food_flag = true;
		return false;
	}
}

void clear_snake()
{
	/*
	Очищается позиция змейки в массиве, т.е. в соответствующей позиции поля устанавливается символ-заполнитель поля.
	*/
	// наверное, после шага змейки, если змея не съела и не увеличилась, то надо подчистить предыдущую позицию хвоста

}

void handle_cmd(const unsigned int& step, DIRECTION& direction)
{
	/*
	Направление движения, признак окончания игры [возможно что-то еще
	*/

	switch (step)
	{
	case LEFT:
		direction = DIRECTION_LEFT;
		break;
	case RIGHT:
		direction = DIRECTION_RIGHT;
		break;
	}
}
