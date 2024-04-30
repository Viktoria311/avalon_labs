#pragma once



void init_food();

void generate_food(char* field, 
					bool game_on, 
					bool& food_flag, 
					unsigned int& food_x,
					unsigned int& food_y);