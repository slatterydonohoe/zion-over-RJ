//
//  Possession.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include "Possession.h"

Possession::Possession(int pts, bool tm) :
m_isTeamPlay(tm),
m_points(pts)
{
	
}
bool Possession::getTeamPlay()
{
	return m_isTeamPlay;
}
int Possession::getPoints()
{
	return m_points;
}
