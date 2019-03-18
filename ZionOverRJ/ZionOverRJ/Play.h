//
//  Play.h
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef Play_h
#define Play_h

#include <stdio.h>
#include "enums.h"

class Play
{
public:
	Play(std::string text, enums::PLAYTYPE play, int pts, bool tm);
	void setEndOfPoss(bool endOfPoss);
	enums::PLAYTYPE getPlayType();
	std::string getText();
	bool getTeamPlay();
	int getPoints();
	bool getEndOfPoss();

private:
	std::string m_text;
	enums::PLAYTYPE m_playType;
	int m_points;
	bool m_isTeamPlay;
	bool m_endOfPoss;
	
};

#endif /* Play_h */
