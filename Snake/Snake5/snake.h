#pragma once
#include "const.h"

extern unsigned int snake_size;

extern DIRECTION direction;

extern unsigned int snake_x[L]; // ������ ���������. ������� ���� ��� ���� ������

void init_snake();

void move_snake(const unsigned int& step);

void add_tail(const unsigned int& step);

bool are_sequentially(); // ����� �� �������� ������ ���� � �����