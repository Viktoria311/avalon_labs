#include "const.h"
#include "game.h"
#include "snake.h"
#include <windows.h>
#include <iostream>

int main()
{
	int position = 1; // там где голова
	
	const char* cls = "cls";

	while (columns >= snake_size && position <= columns)
	{
		system(cls); // функция стирания экрана в <windows.h>

		// колич пробелов   colums - position - (snake_size - 1)
		// тело змейки   position - snake_size

		if (position > snake_size) // если длина змейки меньше ее позиции
		{
			for (int i = 0; i < position - snake_size; ++i) // рисуем необходимое количество пробелов
			{
				std::cout << ' ';
			}
		}

		if (position < snake_size) // если змейка не вся видна в начале
		{
			for (int i = 0; i < position; ++i) // рисуем хвост
			{
				std::cout << tail_symbol;
			}
		}
		else if (position >= snake_size) // если змейка вся выползла
		{
			for (int i = 0; i < snake_size - 1; ++i) // рисуем хвост
			{
				std::cout << tail_symbol;
			}
		}
		
		

		std::cout << head_symbol;  // рисуем голову

		for (int i = 1; i < (columns - position); ++i) // рисуем остатки поля
		{
			std::cout << ' ';
		}

		++position;
		Sleep(timeout);
	}

	return 0;
}