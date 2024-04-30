#pragma once

// extern bool food_flag;

// extern unsigned int food_x;

void init_food();

void generate_food(char* field, 
					bool game_on, 
					bool& food_flag, 
					unsigned int& food_x);