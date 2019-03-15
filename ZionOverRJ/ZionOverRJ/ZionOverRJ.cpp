// ZionOverRJ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "enums.h"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	std::string sPlay, sLineup, sPoints;
	enums::PLAYTYPE ptPlay;
	enums::PLAYERNAME pnPlayer;
	int points;
	bool complete = false;
	std::cout << "Enter starting lineup:\n";
	std::cin >> sLineup;
	while (!complete)
	{
		std::cout << "Enter play type:\n";
		std::cin >> sPlay;
		ptPlay = toPlayType(sPlay);
		switch (ptPlay)
		{
		case enums::OFFENSE:
			std::cout << "Enter number of points scored on offensive possession:\n";
			std::cin >> sPoints;
			break;
		case enums::DEFENSE:
			std::cout << "Enter number of points scored on defensive possession:\n";
			std::cin >> sPoints;
			break;
		case enums::LINEUP:
			std::cout << "Enter lineup (last names, space-delimited):\n";
			std::cin >> sLineup;
			break;

		}
	}
}
