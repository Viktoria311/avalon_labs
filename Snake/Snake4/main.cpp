#include "game.h"
#include "snake.h"
#include "const.h"
#include "field.h"
#include "food.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>




int main()
{

	const char* cls = "cls";
	snake_x[0] = 3; // 0 и column-1 нельзя
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	field[snake_x[0]] = head_symbol;
	game_on = true;
	DIRECTION direction;

	// УСТАНОВКА ЕДЫ НА ПОЛЕ
	srand(time(0));

	do
	{
		food_x = rand() % (columns - 1);
	} while (field[food_x] != ' ');
	field[food_x] = food_symbol;
	food_flag = true;

	unsigned int step;

	// приглашение в игру
	for (int i = 0; i < columns; ++i)
	{
		std::cout << border_symbol;
	}
	std::cout << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << field[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << border_symbol;
	}
	std::cout << std::endl;


	while (game_on && _getch() != ESC ) // может поменять проверку местами?
	{
		system(cls); // функция стирания экрана в <windows.h>
		/* надо упростить
		switch (direction) {
		case RIGHT: snake_x[0] += 1; break;
		case LEFT:  snake_x[0] -= 1; break;
		}
		*/
		
		

		step = _getch(); //  выбор направления

		switch (step)
		{
		case LEFT:
			direction = DIRECTION_LEFT;
			break;
		case RIGHT:
			direction = DIRECTION_RIGHT;
			break;
		}

		switch (direction)
		{
		case DIRECTION_LEFT:
		{
			// меняем голову и хвост местами, если надо
			 // если позиция головы правее кончика хвоста, а шагать надо влево , 
			// И если ситуация *оо   Qо*
			if ( (snake_x[0] > snake_x[snake_size - 1] && are_sequentially() ) ||  // *   оооQ  *
				 (snake_x[0] < snake_x[snake_size - 1] && !are_sequentially() )  ) // *ооQ   ооо* 
			{
				unsigned int helper;
				// changed places
				for (int i = 0; i < snake_size / 2; ++i)
				{
					helper = snake_x[i]; // меняем координаты головы и кончика хвоста  и остальных частей симметрично
					snake_x[i] = snake_x[snake_size - 1 - i];
					snake_x[snake_size - 1 - i] = helper;
				}
			}

			for (int i = 0; i < snake_size; ++i) // меняем положение змейки на 1 назад
			{
				if (snake_x[i] == 1)
					snake_x[i] = columns - 2; // переводим позицию  в самый конец поля
				else
					--(snake_x[i]);

			}
		
			break;
		}
		case DIRECTION_RIGHT:
		{
			// меняем голову и хвост местами, если надо
			// если позиция головы левее кончика хвоста, а шагать надо вправо
			// И если  *ооо  Qоо*
			
			if ( (snake_x[0] < snake_x[snake_size - 1] && are_sequentially() )  || // *   Qооо  *
				 (snake_x[0] > snake_x[snake_size - 1] && !are_sequentially() ) )  // *ооо   Qоо* 
			{
				unsigned int helper;
				// changed places
				for (int i = 0; i < snake_size / 2; ++i)
				{
					helper = snake_x[i]; // меняем координаты головы и кончика хвоста  и остальных частей симметрично
					snake_x[i] = snake_x[snake_size - 1 - i];
					snake_x[snake_size - 1 - i] = helper;
				}
			}


			for (int i = 0; i < snake_size; ++i) // меняем положение змейки на 1 вперед
			{
				if (snake_x[i] == columns - 2)
					snake_x[i] = 1; // переводим позицию  в самое начало поля
				else
					++(snake_x[i]);

			}

			break;
		}
		default:
			//std::cout << "Eror" << std::endl;
			break;
		}

		// шаг змейки. Если съела еду, тело увеличить на 1.
		// И если  snake_size > L конец игры  break; выходим из тела цикла игры -  учтено в условии while
		{
			// написать код для этой логики
			if (snake_x[0] == food_x) // если змейка съела еду
			{
				food_flag = false;
				
				++snake_size;
				// увеличить тело змеи на 1
				if (step == LEFT) // учитывать крайние случаи !!!
				{
					// если преждний хвост 
					if (snake_x[snake_size - 2] == columns - 2) // если координата прошлого хвоста стала впритык со стенкой справа
						snake_x[snake_size - 1] = 1; // новый хвост будет с другой стороны
					else
						snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1; // координата нового хвоста = координата правее на единицу прошлого хвоста
				}
				else // step == RIGHT
				{
					if (snake_x[snake_size - 2]  == 1) // если координата прошлого хвоста  стала впритык со стенкой слева
						snake_x[snake_size - 1] = columns - 2; // новый хвост будет с другой стороны
					else
						snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1; // координата нового хвоста = координата левее на единицу прошлого хвоста
				}
					

			}
				
		}
		

		{ // наново заполняем поле игры символами
			field[0] = border_symbol;
			field[columns - 1] = border_symbol;

			for (int i = 1; i < columns - 1; ++i) // пробелы по всему полю
				field[i] = field_symbol;

			if (food_flag == true)
				field[food_x] = food_symbol;

			for (int i = 1; i < snake_size; ++i) // хвост
			{
				field[snake_x[i]] = tail_symbol;
			}
			field[snake_x[0]] = head_symbol; // голова
		}
		
		if (snake_size >= L)
			game_on = false;


		if (game_on && food_flag == false)// установить еду рандомно food_x - координата еды
		{
			do
			{
				food_x = rand() % (columns - 1);
			} while (field[food_x] != ' ');
			field[food_x] = food_symbol;
			food_flag = true;
		}

		for (int i = 0; i < columns; ++i)
		{
			std::cout << border_symbol;
		}
		std::cout << std::endl;
		for (int i = 0; i < columns; ++i)
		{
			std::cout << field[i];
		}
		std::cout << std::endl;
		for (int i = 0; i < columns; ++i)
		{
			std::cout << border_symbol;
		}
		std::cout << std::endl;
		
		
	}
	std::cout << "BYE" << std::endl;

	return 0;
}