#pragma once

#include "const.h"

struct Game;


struct field
{
	// ������ �������� ����
	char** Field;

	// ����� �������� ���� �� �����������
	unsigned int columns;

	// ����� �������� ���� �� ���������
	unsigned int rows;
};

// ����������� ������
void create_field(Game& my_game);

// ����������� ������
void destroy_field(Game& my_game);

void init_field(Game& my_game);

void print_field(const Game& my_game);
void clear_field(Game& my_game);
void init_borders(Game& my_game);
