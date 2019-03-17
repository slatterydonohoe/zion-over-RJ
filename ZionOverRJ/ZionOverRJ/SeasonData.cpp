//
//  SeasonData.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include "SeasonData.h"
#include <vector>

SeasonData::SeasonData(std::vector<Play*>* playData) :
m_playData(playData)
{
	findEndsOfPossessions();
}

void SeasonData::findEndsOfPossessions()
{
	for (std::vector<Play*>::iterator itr = m_playData->begin(); itr != m_playData->end(); itr++)
	{
		bool endOfPoss = false;
		enums::PLAYTYPE p = (*itr)->getPlayType();
		switch (p)
		{
			case enums::PLAYTYPE::DRB:
			case enums::PLAYTYPE::TOV:
			{
				endOfPoss = true;
				break;
			}
			case enums::PLAYTYPE::FTMAKE:
			{
				std::string text = (*itr)->getText();
				if ((text.find("one of one") != std::string::npos) ||
					(text.find("two of two") != std::string::npos) ||
					(text.find("three of three") != std::string::npos))
				{
					endOfPoss = true;
				}
				break;
			}
			case enums::PLAYTYPE::FGMAKE:
			{
				std::vector<Play*>::iterator next = itr;
				next++;
				if (next != m_playData->end())
				{
					if ((*next)->getPlayType() != enums::PLAYTYPE::SHFOUL ||
						(*next)->getTeamPlay() == (*itr)->getTeamPlay())
					{
						endOfPoss = true;
					}
				}
				break;
			}
			default:
			{
				break;
			}
		}
		(*itr)->setEndOfPoss(endOfPoss);
	}
}

void SeasonData::populatePossessions()
{
	
	/*for (auto p : *m_playData)
	{
		
	}*/
}
