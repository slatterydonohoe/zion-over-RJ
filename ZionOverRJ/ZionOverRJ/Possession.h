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

class Possession
{
public:
	Possession(int pts, bool tm);
	bool getTeamPlay();
	int getPoints();
private:
	bool m_isTeamPlay;
	int m_points;
};

#endif /* Possession_h */
