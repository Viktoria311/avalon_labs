#pragma once


struct field;
struct Game;

struct food
{
	// �������, ��� ��� �����������
	bool food_flag = false;

	// ���������� ��� ��  ����������� (X)
	unsigned int food_x;

	// ���������� ��� ��  ��������� (Y)
	unsigned int food_y;
};

void init_food();

void generate_food(field& my_field,
					Game& my_game,
					food& my_food);