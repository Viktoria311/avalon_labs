#pragma once

const unsigned int columns = 10;
const char food_symbol = '+';
const char tail_symbol = 'o';
const char head_symbol = 'Q';
const char field_symbol = ' ';
const char border_symbol = '*';
const unsigned int L = columns - 2; // не должна быть > длины игрового поля-2
enum DIRECTION { DIRECTION_LEFT, DIRECTION_RIGHT };
enum KYES { RIGHT = 77, LEFT = 75, TOP = 72, BOTTOM = 80, ESC = 27 };