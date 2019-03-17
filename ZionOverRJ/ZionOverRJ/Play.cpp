//
//  Play.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include "Play.h"

Play::Play(enums::PLAYTYPE play, int pts, bool tm) :
m_playType(play),
m_points(pts),
m_isTeamPlay(tm),
m_endOfPoss(false)
{
}

void Play::setEndOfPoss(bool endOfPoss)
{
	m_endOfPoss = endOfPoss;
}
