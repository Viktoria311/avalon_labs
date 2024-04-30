
#include <conio.h>
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <windows.h>





void init_game(Game& my_game)
{
	create_field(my_game);

	//установка координат головы змейки
	my_game.my_snake.snake_x[0] = 1; // 0 и column-1 нельзя
	my_game.my_snake.snake_y[0] = 1;

	init_field(my_game);
	generate_food(my_game);
	print_field(const_cast<const Game&>(my_game)); // приглашение в игру
}

void next_step(Game& my_game)
{
	unsigned int step;

	step = _getch(); // выбор направления

	handle_cmd(step, my_game);

	move_snake(my_game, step);

	init_field(my_game); // наново заполняем поле игры символами

	generate_food(my_game);

	print_field(const_cast<const Game&>(my_game));
}

void exec_game(Game& my_game)
{
	while (my_game.game_on && _getch() != ESC)
	{
		next_step(my_game);
	}
}

void set_snake(Game& my_game)
{
	/*
	Змейка устанавливается в игровом поле, т.е.
	•	символ головы змейки копируется в соответствующую позицию игрового поля
	•	символы хвоста также копируются в игровое поле.
	*/
	//field[snake_y[0] * columns + snake_x[0]] = head_symbol;
	my_game.my_field.Field[my_game.my_snake.snake_y[0] ][my_game.my_snake.snake_x[0] ] = head_symbol;

	for (int i = 1; i < my_game.my_snake.snake_size; ++i)
		my_game.my_field.Field[my_game.my_snake.snake_y[i] ][my_game.my_snake.snake_x[i] ] = tail_symbol;
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

bool check_eating(Game& my_game)
{
	/*
	Выполняется проверка того, что змейка съела еду.
	Если координаты еды и координаты головы змейки совпадают,
	то  устанавливается в false признак того, что еда есть на поле.
	*/
	if (my_game.my_snake.snake_x[0] == my_game.my_food.food_x && 
		my_game.my_snake.snake_y[0] == my_game.my_food.food_y)
	{
		my_game.my_food.food_flag = false;
		++my_game.my_snake.snake_size; // увеличить тело змеи на 1
		return true;
	}

	else
	{
		my_game.my_food.food_flag = true;
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

void handle_cmd(const unsigned int& step, Game& my_game)
{
	/*
	Направление движения, признак окончания игры [возможно что-то еще
	*/

	switch (step)
	{
	case LEFT:
		my_game.my_snake.direction = DIRECTION_LEFT;
		break;
	case RIGHT:
		my_game.my_snake.direction = DIRECTION_RIGHT;
		break;
	case TOP:
		my_game.my_snake.direction = DIRECTION_TOP;
		break;
	case BOTTOM:
		my_game.my_snake.direction = DIRECTION_BOTTOM;
		break;
	}
}
