#include "const.h"
#include "game.h"
#include "snake.h"
#include <windows.h>
#include <iostream>

int main()
{
	int position = 1; // ��� ��� ������
	
	const char* cls = "cls";

	while (columns >= snake_size && position <= columns)
	{
		system(cls); // ������� �������� ������ � <windows.h>

		// ����� ��������   colums - position - (snake_size - 1)
		// ���� ������   position - snake_size

		if (position > snake_size) // ���� ����� ������ ������ �� �������
		{
			for (int i = 0; i < position - snake_size; ++i) // ������ ����������� ���������� ��������
			{
				std::cout << ' ';
			}
		}

		if (position < snake_size) // ���� ������ �� ��� ����� � ������
		{
			for (int i = 0; i < position; ++i) // ������ �����
			{
				std::cout << tail_symbol;
			}
		}
		else if (position >= snake_size) // ���� ������ ��� ��������
		{
			for (int i = 0; i < snake_size - 1; ++i) // ������ �����
			{
				std::cout << tail_symbol;
			}
		}
		
		

		std::cout << head_symbol;  // ������ ������

		for (int i = 1; i < (columns - position); ++i) // ������ ������� ����
		{
			std::cout << ' ';
		}

		++position;
		Sleep(timeout);
	}

	return 0;
}