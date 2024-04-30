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
	snake_x[0] = 3; // 0 � column-1 ������
	field[0] = border_symbol;
	field[columns - 1] = border_symbol;
	field[snake_x[0]] = head_symbol;
	game_on = true;
	DIRECTION direction;

	// ��������� ��� �� ����
	srand(time(0));

	do
	{
		food_x = rand() % (columns - 1);
	} while (field[food_x] != ' ');
	field[food_x] = food_symbol;
	food_flag = true;

	unsigned int step;

	// ����������� � ����
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


	while (game_on && _getch() != ESC ) // ����� �������� �������� �������?
	{
		system(cls); // ������� �������� ������ � <windows.h>
		/* ���� ���������
		switch (direction) {
		case RIGHT: snake_x[0] += 1; break;
		case LEFT:� snake_x[0] -= 1; break;
		}
		*/
		
		

		step = _getch(); //  ����� �����������

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
			// ������ ������ � ����� �������, ���� ����
			 // ���� ������� ������ ������ ������� ������, � ������ ���� ����� , 
			// � ���� �������� *��   Q�*
			if ( (snake_x[0] > snake_x[snake_size - 1] && are_sequentially() ) ||  // *   ���Q  *
				 (snake_x[0] < snake_x[snake_size - 1] && !are_sequentially() )  ) // *��Q   ���* 
			{
				unsigned int helper;
				// changed places
				for (int i = 0; i < snake_size / 2; ++i)
				{
					helper = snake_x[i]; // ������ ���������� ������ � ������� ������  � ��������� ������ �����������
					snake_x[i] = snake_x[snake_size - 1 - i];
					snake_x[snake_size - 1 - i] = helper;
				}
			}

			for (int i = 0; i < snake_size; ++i) // ������ ��������� ������ �� 1 �����
			{
				if (snake_x[i] == 1)
					snake_x[i] = columns - 2; // ��������� �������  � ����� ����� ����
				else
					--(snake_x[i]);

			}
		
			break;
		}
		case DIRECTION_RIGHT:
		{
			// ������ ������ � ����� �������, ���� ����
			// ���� ������� ������ ����� ������� ������, � ������ ���� ������
			// � ����  *���  Q��*
			
			if ( (snake_x[0] < snake_x[snake_size - 1] && are_sequentially() )  || // *   Q���  *
				 (snake_x[0] > snake_x[snake_size - 1] && !are_sequentially() ) )  // *���   Q��* 
			{
				unsigned int helper;
				// changed places
				for (int i = 0; i < snake_size / 2; ++i)
				{
					helper = snake_x[i]; // ������ ���������� ������ � ������� ������  � ��������� ������ �����������
					snake_x[i] = snake_x[snake_size - 1 - i];
					snake_x[snake_size - 1 - i] = helper;
				}
			}


			for (int i = 0; i < snake_size; ++i) // ������ ��������� ������ �� 1 ������
			{
				if (snake_x[i] == columns - 2)
					snake_x[i] = 1; // ��������� �������  � ����� ������ ����
				else
					++(snake_x[i]);

			}

			break;
		}
		default:
			//std::cout << "Eror" << std::endl;
			break;
		}

		// ��� ������. ���� ����� ���, ���� ��������� �� 1.
		// � ����  snake_size > L ����� ����  break; ������� �� ���� ����� ���� -  ������ � ������� while
		{
			// �������� ��� ��� ���� ������
			if (snake_x[0] == food_x) // ���� ������ ����� ���
			{
				food_flag = false;
				
				++snake_size;
				// ��������� ���� ���� �� 1
				if (step == LEFT) // ��������� ������� ������ !!!
				{
					// ���� �������� ����� 
					if (snake_x[snake_size - 2] == columns - 2) // ���� ���������� �������� ������ ����� ������� �� ������� ������
						snake_x[snake_size - 1] = 1; // ����� ����� ����� � ������ �������
					else
						snake_x[snake_size - 1] = snake_x[snake_size - 2] + 1; // ���������� ������ ������ = ���������� ������ �� ������� �������� ������
				}
				else // step == RIGHT
				{
					if (snake_x[snake_size - 2]  == 1) // ���� ���������� �������� ������  ����� ������� �� ������� �����
						snake_x[snake_size - 1] = columns - 2; // ����� ����� ����� � ������ �������
					else
						snake_x[snake_size - 1] = snake_x[snake_size - 2] - 1; // ���������� ������ ������ = ���������� ����� �� ������� �������� ������
				}
					

			}
				
		}
		

		{ // ������ ��������� ���� ���� ���������
			field[0] = border_symbol;
			field[columns - 1] = border_symbol;

			for (int i = 1; i < columns - 1; ++i) // ������� �� ����� ����
				field[i] = field_symbol;

			if (food_flag == true)
				field[food_x] = food_symbol;

			for (int i = 1; i < snake_size; ++i) // �����
			{
				field[snake_x[i]] = tail_symbol;
			}
			field[snake_x[0]] = head_symbol; // ������
		}
		
		if (snake_size >= L)
			game_on = false;


		if (game_on && food_flag == false)// ���������� ��� �������� food_x - ���������� ���
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