
#include <conio.h>
#include "const.h"
#include "game.h"
#include "winconsole.h"
#include <windows.h>





void init_game(Game& my_game)
{
	create_field(my_game);

	//��������� ��������� ������ ������
	my_game.my_snake.snake_x[0] = 1; // 0 � column-1 ������
	my_game.my_snake.snake_y[0] = 1;

	init_field(my_game);
	generate_food(my_game);
	print_field(const_cast<const Game&>(my_game)); // ����������� � ����
}

void next_step(Game& my_game)
{
	unsigned int step;

	step = _getch(); // ����� �����������

	handle_cmd(step, my_game);

	move_snake(my_game, step);

	init_field(my_game); // ������ ��������� ���� ���� ���������

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
	������ ��������������� � ������� ����, �.�.
	�	������ ������ ������ ���������� � ��������������� ������� �������� ����
	�	������� ������ ����� ���������� � ������� ����.
	*/
	//field[snake_y[0] * columns + snake_x[0]] = head_symbol;
	my_game.my_field.Field[my_game.my_snake.snake_y[0] ][my_game.my_snake.snake_x[0] ] = head_symbol;

	for (int i = 1; i < my_game.my_snake.snake_size; ++i)
		my_game.my_field.Field[my_game.my_snake.snake_y[i] ][my_game.my_snake.snake_x[i] ] = tail_symbol;
}

void set_food()
{
	/*
	��� ��������������� � ������� ����.  ����� �������� ������� generate_food() � ���������, ��� � ��������������� ������� ������ ���.
	*/
	// ����� �������� ��� ���� �������
}

void check_game()
{
	/*
	���������, ��� ������ �������� ������ ������������� �������
	*/

}

void check_snake()
{
	/*
	����������� �������� ����, ��� ������ ����������� � �������� ����.
	� ����������� �� ����������� �������� ������ ����� ����������� ��� � ������, ��� � � ����� �������� ���� ����.

	�����!
	�	���� ������ ������ ��������� � ������, �� �������� ������ ���� �� ������,
	�.�.  ��� ���������� � ������� (����������������) ���� ����.
	*/


}

bool check_eating(Game& my_game)
{
	/*
	����������� �������� ����, ��� ������ ����� ���.
	���� ���������� ��� � ���������� ������ ������ ���������,
	��  ��������������� � false ������� ����, ��� ��� ���� �� ����.
	*/
	if (my_game.my_snake.snake_x[0] == my_game.my_food.food_x && 
		my_game.my_snake.snake_y[0] == my_game.my_food.food_y)
	{
		my_game.my_food.food_flag = false;
		++my_game.my_snake.snake_size; // ��������� ���� ���� �� 1
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
	��������� ������� ������ � �������, �.�. � ��������������� ������� ���� ��������������� ������-����������� ����.
	*/
	// ��������, ����� ���� ������, ���� ���� �� ����� � �� �����������, �� ���� ���������� ���������� ������� ������

}

void handle_cmd(const unsigned int& step, Game& my_game)
{
	/*
	����������� ��������, ������� ��������� ���� [�������� ���-�� ���
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
