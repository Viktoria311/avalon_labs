#include "snake.h"
#include "const.h"

unsigned int snake_size = 1;

DIRECTION direction = DIRECTION_RIGHT; // enum DIRECTION {};

unsigned int snake_x[L] = { 0 }; // ������ ���������. ������� ���� ��� ���� ������. ������ ������ [0]. 
