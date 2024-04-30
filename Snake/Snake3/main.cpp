#include "game.h"
#include "snake.h"
#include "const.h"
#include "field.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

// �������
// ������������ ����������� ����� ����
// ��� ����  enum DIRECTION  � enum  KYES. ������ �� �� ����� ������ ���� �� ��� ?
// ��� ���� bool game_on , ���� ���������� ����� ����  �������� = _getch() ?

int main()
{

	const char* cls = "cls";
	snake_x[0] =  3; // 0 � column-1 ������
	field[0] = '*';
	field[columns - 1] = '*';
	field[ snake_x[0] ] = head_symbol;

	unsigned int step;

	// ����������� � ����
	std::cout << "**********" << std::endl;
	for (int i = 0; i < columns; ++i)
	{
		std::cout << field[i];
	}
	std::cout << std::endl 
		      << "**********" << std::endl << "Enter ";
	
	
	while (_getch() != ESC)
	{
		system(cls); // ������� �������� ������ � <windows.h>

		step = _getch();

		switch (step)
		{
		case LEFT: // ��  KYES
		{
			field[snake_x[0]] = ' ';

			if (snake_x[0] == 1) // ���� ������� ������ ������� �����
				snake_x[0] = columns - 2; // ��������� ������� ������ � ����� ����� ����
			else
				--(snake_x[0]);

			field[snake_x[0]] = head_symbol;
			break;
		}
		case RIGHT: // ��  KYES  step 77
		{
			system(cls); // ������� �������� ������ � <windows.h>

			field[snake_x[0]] = ' ';

			if (snake_x[0] == columns - 2) // ���� ������� ������ ������� ������
				snake_x[0] = 1; // ��������� ������� ������ � ����� ������
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