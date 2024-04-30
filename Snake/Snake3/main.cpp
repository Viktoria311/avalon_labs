#include "game.h"
#include "snake.h"
#include "const.h"
#include "field.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

// ВОПРОСЫ
// НЕПРАВИЛЬНОЕ ОТОБРАЖЕНИЕ КРАЁВ ПОЛЯ
// ДЛЯ ЧЕГО  enum DIRECTION  И enum  KYES. пОЧЕМУ БЫ НЕ ИМЕТЬ ТОЛЬКО ОДИН ИЗ НИХ ?
// ДЛЯ ЧЕГО bool game_on , ЕСЛИ РЕГУЛИРУЕМ КОНЕЦ ИГРЫ  ФУНКЦИЕЙ = _getch() ?

int main()
{

	const char* cls = "cls";
	snake_x[0] =  3; // 0 и column-1 нельзя
	field[0] = '*';
	field[columns - 1] = '*';
	field[ snake_x[0] ] = head_symbol;

	unsigned int step;

	// приглашение в игру
	std::cout << "**********" << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << field[i];
	}
	std::cout << std::endl 
		      << "**********" << std::endl << "Enter ";
	
	
	while (_getch() != ESC)
	{
		system(cls); // функция стирания экрана в <windows.h>

		step = _getch();

		switch (step)
		{
		case LEFT: // из  KYES
		{
			field[snake_x[0]] = ' ';

			if (snake_x[0] == 1) // если позиция головы крайняя слева
				snake_x[0] = columns - 2; // переводим позицию головы в самый конец поля
			else
				--(snake_x[0]);

			field[snake_x[0]] = head_symbol;
			break;
		}
		case RIGHT: // из  KYES  step 77
		{
			system(cls); // функция стирания экрана в <windows.h>

			field[snake_x[0]] = ' ';

			if (snake_x[0] == columns - 2) // если позиция головы крайняя справа
				snake_x[0] = 1; // переводим позицию головы в самое начало
			else
				++(snake_x[0]);

			field[snake_x[0]] = head_symbol;
			break;
		}
		default:
			//std::cout << "Eror" << std::endl;
			break;
		}

		std::cout << "**********" << std::endl;
		for (int i = 0; i < columns; ++i)
		{
			std::cout << field[i];
		}
		std::cout << std::endl << "**********" << std::endl;
	}


	return 0;
}