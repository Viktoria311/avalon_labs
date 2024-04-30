#include "game.h"
#include "const.h"
#include "snake.h"
#include "field.h"
#include "food.h"




void init_game(snake& my_snake)
{
	//установка координат головы змейки
	my_snake.snake_x[0] = 1; // 0 и column-1 нельзя
	my_snake.snake_y[0] = 1;
}

void set_snake(field& my_field,
				snake& my_snake)
{
	/*
	Змейка устанавливается в игровом поле, т.е.
	•	символ головы змейки копируется в соответствующую позицию игрового поля
	•	символы хвоста также копируются в игровое поле.
	*/
	//field[snake_y[0] * columns + snake_x[0]] = head_symbol;
	my_field.Field[my_snake.snake_y[0] ][my_snake.snake_x[0] ] = head_symbol;

	for (int i = 1; i < my_snake.snake_size; ++i)
		my_field.Field[my_snake.snake_y[i] ][my_snake.snake_x[i] ] = tail_symbol;
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

bool check_eating(snake& my_snake,
					food& my_food)
{
	/*
	Выполняется проверка того, что змейка съела еду.
	Если координаты еды и координаты головы змейки совпадают,
	то  устанавливается в false признак того, что еда есть на поле.
	*/
	if (my_snake.snake_x[0] == my_food.food_x && my_snake.snake_y[0] == my_food.food_y)
	{
		my_food.food_flag = false;
		++my_snake.snake_size; // увеличить тело змеи на 1
		return true;
	}

	else
	{
		my_food.food_flag = true;
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

void handle_cmd(const unsigned int& step, snake& my_snake)
{
	/*
	Направление движения, признак окончания игры [возможно что-то еще
	*/

	switch (step)
	{
	case LEFT:
		my_snake.direction = DIRECTION_LEFT;
		break;
	case RIGHT:
		my_snake.direction = DIRECTION_RIGHT;
		break;
	case TOP:
		my_snake.direction = DIRECTION_TOP;
		break;
	case BOTTOM:
		my_snake.direction = DIRECTION_BOTTOM;
		break;
	}
}
