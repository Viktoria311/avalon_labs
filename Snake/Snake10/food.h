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

void generate_food(Game& my_game);