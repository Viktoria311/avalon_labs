#pragma once

#include "const.h"

extern unsigned int timeout; // >100 (ms)

extern bool game_on;


void init_game();

void set_snake();

void set_food();

void check_game();
void check_snake();
bool check_eating();
void clear_snake();
void handle_cmd(const unsigned int& step);