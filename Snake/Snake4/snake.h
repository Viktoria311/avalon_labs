#pragma once
#include "const.h"

extern unsigned int snake_size;

extern DIRECTION direction;

extern unsigned int snake_x[L]; // массив координат. индексы поля где есть змейка

bool are_sequentially(); // рядом ли элементы змейки друг к другу