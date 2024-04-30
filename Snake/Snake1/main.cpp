#include <iostream>
#include <conio.h>

int main()
{
	char step = 0;

	std::cout << "Version 1:" << std::endl;
	std::cout << "Enter a, s,  w,  d (0  for exit):" << std::endl;

	while (std::cin >> step && step != '0')
	{
		switch (step)
		{
		case 'a':
		case 'A':
			std::cout << '<' << std::endl;
			break;
		case 'w':
		case 'W':
			std::cout << '^' << std::endl;
			break;
		case 'd':
		case 'D':
			std::cout << '>' << std::endl;
			break;
		case 's':
		case 'S':
			std::cout << 'v' << std::endl;
			break;
		default:
			std::cout << "Error" << std::endl;
		}
	}
	if (!std::cin)
	{
		std::cin.clear();
		std::cout << "Error input" << std::endl;
	}

	std::cout << "Version 2:" << std::endl;
	std::cout << "Enter a, s,  w,  d (ESC  for exit):" << std::endl;
	
	do
	{
		step = _getch();

		switch (step)
		{
		case 27:
			std::cout << "Exit" << std::endl;
			break;
		case 'a':
		case 'A':
			std::cout << '<' << std::endl;
			break;
		case 'w':
		case 'W':
			std::cout << '^' << std::endl;
			break;
		case 'd':
		case 'D':
			std::cout << '>' << std::endl;
			break;
		case 's':
		case 'S':
			std::cout << 'v' << std::endl;
			break;
		default:
			std::cout << "Error" << std::endl;
		}
	} while (step != 27);
	


	std::cout << "Version 3:" << std::endl;
	std::cout << "Enter  RIGHT, LEFT, TOP, BOTTOM   (ESC  for exit):" << std::endl;

	unsigned int stepU = 0;

	enum STEP { RIGHT = 77, LEFT = 75, TOP = 72, BOTTOM = 80, ESC = 27 };

	while (true)
	{
		if((stepU = _getch()) == 0 || stepU == 224) /* функциональная ли клавиша */
		{
			stepU = _getch(); /* получаем код клавиши */

			switch (stepU)
			{
			case LEFT:
				std::cout << '<' << std::endl;
				break;
			case TOP:
				std::cout << '^' << std::endl;
				break;
			case RIGHT:
				std::cout << '>' << std::endl;
				break;
			case BOTTOM:
				std::cout << 'v' << std::endl;
				break;
			default:
				std::cout << "Error" << std::endl;
				//std::cout << "Error" << std::endl;
			}
		}
		else
		{
			if (stepU == ESC)
			{
				std::cout << "Exit" << std::endl;
				break;
			}
			else
				std::cout << "Error" << std::endl;
		}

	}

	return 0;
}