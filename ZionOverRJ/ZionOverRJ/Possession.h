//
//  Possession.hpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef Possession_h
#define Possession_h

#include <stdio.h>
#include <string>

class Possession
{
public:
	Possession(std::string lineup, int pts, bool tm);
	bool getTeamPlay();
	int getPoints();
	std::string getLineupText();
private:
	bool m_isTeamPlay;
	int m_points;
	std::string m_lineupText;
};

#endif /* Possession_h */
