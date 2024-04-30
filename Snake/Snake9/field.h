#pragma once

#include "const.h"

struct food;
struct snake;

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
void create_field(field& my_field);

// ����������� ������
void destroy_field(field& my_field);

void init_field(field& my_field,
				food& my_food,
				snake& my_snake);

void print_field(const field& my_field);
void clear_field(field& my_field);
void init_borders(field& my_field);
