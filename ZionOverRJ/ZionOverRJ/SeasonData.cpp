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
	m_Zion = new Player("Zion Williamson");
	m_RJ = new Player("R.J. Barrett");
	m_possessionData = new std::vector<Possession*>();
	findEndsOfPossessions();
	populatePossessions();
	organizePlayerData();
}

void SeasonData::findEndsOfPossessions()
{
	for (std::vector<Play*>::iterator itr = m_playData->begin(); itr != m_playData->end(); itr++)
	{
		bool endOfPoss = false;
		enums::PLAYTYPE p = (*itr)->getPlayType();
		switch (p)
		{
			case enums::PLAYTYPE::JUMPBALL:
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
			case enums::PLAYTYPE::PFOUL:
			{
				std::vector<Play*>::iterator prev = itr;
				prev--;
				if (itr != m_playData->begin())
				{
					endOfPoss = (((*prev)->getPlayType() == enums::PLAYTYPE::FGMISS ||
								  (*prev)->getPlayType() == enums::PLAYTYPE::FTMISS) &&
								 (*prev)->getTeamPlay() == (*itr)->getTeamPlay());
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
	int points = 0;
	bool isTeamPlay = false;
	std::string lineup = "";
	for (const auto &p : *m_playData)
	{
		points += p->getPoints();
		if (p->getPlayType() == enums::PLAYTYPE::LINEUP && p->getTeamPlay())
		{
			lineup = p->getText();
		}
		if (p->getEndOfPoss())
		{
			isTeamPlay = ((p->getTeamPlay() && (p->getPlayType() == enums::PLAYTYPE::TOV ||
												p->getPlayType() == enums::PLAYTYPE::FGMAKE ||
											   p->getPlayType() == enums::PLAYTYPE::FTMAKE)) ||
						  (!p->getTeamPlay() && (p->getPlayType() == enums::PLAYTYPE::DRB)));
			m_possessionData->push_back(new Possession(lineup, points, isTeamPlay));
			points = 0;
		}
	}
}

void SeasonData::organizePlayerData()
{
	for (const auto &p : *m_possessionData)
	{
		m_Zion->addPossession(p);
		m_RJ->addPossession(p);
	}
	
	/*int z1 = m_Zion->m_defensivePossessionsOnCourt->size();
	int z2 = m_Zion->m_defensivePossessionsOffCourt->size();
	int z3 = m_Zion->m_offensivePossessionsOnCourt->size();
	int z4 = m_Zion->m_offensivePossessionsOffCourt->size();
	
	int r1 = m_RJ->m_defensivePossessionsOnCourt->size();
	int r2 = m_RJ->m_defensivePossessionsOffCourt->size();
	int r3 = m_RJ->m_offensivePossessionsOnCourt->size();
	int r4 = m_RJ->m_offensivePossessionsOffCourt->size();*/
	
	float zionDPTSOnCourt = 0.0, zionDPTSOffCourt = 0.0, zionOPTSOnCourt = 0.0, zionOPTSOffCourt = 0.0;
	float rjDPTSOnCourt = 0.0, rjDPTSOffCourt = 0.0, rjOPTSOnCourt = 0.0, rjOPTSOffCourt = 0.0;
	float zionOPTSper100pos, zionDPTSper100pos, zionTeamOPTSper100pos, zionTeamDPTSper100pos;
	float rjOPTSper100pos, rjDPTSper100pos, rjTeamOPTSper100pos, rjTeamDPTSper100pos;
	
	// defensive on court
	for (const auto &p : *(m_Zion->m_defensivePossessionsOnCourt))
	{
		zionDPTSOnCourt += (float)p->getPoints();
	}
	zionDPTSper100pos = zionDPTSOnCourt / (float)m_Zion->m_defensivePossessionsOnCourt->size();
	
	// defensive off court
	for (const auto &p : *(m_Zion->m_defensivePossessionsOffCourt))
	{
		zionDPTSOffCourt += (float)p->getPoints();
	}
	zionTeamDPTSper100pos = zionDPTSOffCourt / (float)m_Zion->m_defensivePossessionsOffCourt->size();
	
	// offensive on court
	for (const auto &p : *(m_Zion->m_offensivePossessionsOnCourt))
	{
		zionOPTSOnCourt += (float)p->getPoints();
	}
	zionOPTSper100pos = zionOPTSOnCourt / (float)m_Zion->m_offensivePossessionsOnCourt->size();
	
	// offensive off court
	for (const auto &p : *(m_Zion->m_offensivePossessionsOffCourt))
	{
		zionOPTSOffCourt += (float)p->getPoints();
	}
	zionTeamOPTSper100pos = zionOPTSOffCourt / (float)m_Zion->m_offensivePossessionsOffCourt->size();
	
	
	
	
	
	// defensive on court
	for (const auto &p : *(m_RJ->m_defensivePossessionsOnCourt))
	{
		rjDPTSOnCourt += (float)p->getPoints();
	}
	rjDPTSper100pos = rjDPTSOnCourt / (float)m_RJ->m_defensivePossessionsOnCourt->size();
	
	// defensive off court
	for (const auto &p : *(m_RJ->m_defensivePossessionsOffCourt))
	{
		rjDPTSOffCourt += (float)p->getPoints();
	}
	rjTeamDPTSper100pos = rjDPTSOffCourt / (float)m_RJ->m_defensivePossessionsOffCourt->size();
	
	// offensive on court
	for (const auto &p : *(m_RJ->m_offensivePossessionsOnCourt))
	{
		rjOPTSOnCourt += (float)p->getPoints();
	}
	rjOPTSper100pos = rjOPTSOnCourt / (float)m_RJ->m_offensivePossessionsOnCourt->size();
	
	// offensive off court
	for (const auto &p : *(m_RJ->m_offensivePossessionsOffCourt))
	{
		rjOPTSOffCourt += (float)p->getPoints();
	}
	rjTeamOPTSper100pos = rjOPTSOffCourt / (float)m_RJ->m_offensivePossessionsOffCourt->size();
}
