//
//  PlayByPlayParse.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include "PlayByPlayParse.h"
#include "enums.h"
#include <sstream>

PlayByPlayParse::PlayByPlayParse()
{
	m_playerNames.insert(std::make_pair(enums::PLAYER::BARRETT, "R.J. Barrett"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::JONES, "Tre Jones"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::BOLDEN, "Marques Bolden"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::REDDISH, "Cam Reddish"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::WILLIAMSON, "Zion Williamson"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::WHITE, "Jack White"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::DELAURIER, "Javin DeLaurier"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::OCONNELL, "Alex O'Connell"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::GOLDWIRE, "Jordan Goldwire"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::VRANKOVIC, "Antonio Vrankovic"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::ROBINSON, "Justin Robinson"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::BESSER, "Brennan Besser"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::BUCKMIRE, "Mike Buckmire"));
	m_playerNames.insert(std::make_pair(enums::PLAYER::BAKER, "Joey Baker"));
	
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::DRB, "defensive rebound"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::ORB, "offensive rebound"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::FTMAKE, "makes regular free throw"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::FTMISS, "misses regular free throw"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::FGMAKE, "makes"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::FGMISS, "misses"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::SHFOUL, "shooting foul"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::PFOUL, "personal foul"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::OFOUL, "offensive foul"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::TOV, "turnover"));
	m_playTypes.insert(std::make_pair(enums::PLAYTYPE::LINEUP, "lineup change"));
}

std::vector<Play*>* PlayByPlayParse::parseFile(std::ifstream* infile)
{
	std::vector<Play*>* playVec = new std::vector<Play*>();
	Play* play = nullptr;
	std::string line;
	while (std::getline(*infile, line))
	{
		play = parseLine(line);
		if (play)
			playVec->push_back(play);
	}
	return playVec;
}

Play* PlayByPlayParse::parseLine(std::string line)
{
	enums::PLAYTYPE playType = enums::PLAYTYPE::NOPLAY;
	int pts = 0;
	bool isTeamPlay = false;
	
	if (line.find(m_playTypes[enums::PLAYTYPE::LINEUP]) != std::string::npos)
	{
		playType = enums::PLAYTYPE::LINEUP;
		isTeamPlay = line.find("Devils")!= std::string::npos;
		return new Play(line, playType, pts, isTeamPlay);
	}
	else
	{
		std::string trimmedLine;
		std::stringstream lineStream(line);
		if (getline(lineStream, trimmedLine, '('))
		{
			for (const auto &pt : m_playTypes)
			{
				if (trimmedLine.find(pt.second) != std::string::npos)
				{
					playType = pt.first;
					break;
				}
			}
			if (playType != enums::PLAYTYPE::NOPLAY)
			{
				for (const auto &pn : m_playerNames)
				{
					if (trimmedLine.find(pn.second) != std::string::npos)
					{
						isTeamPlay = true;
						break;
					}
				}
				switch (playType)
				{
					case enums::PLAYTYPE::FGMAKE:
						if (trimmedLine.find("three point") != std::string::npos)
							pts = 3;
						else if (trimmedLine.find("two point") != std::string::npos)
							pts = 2;
						break;
					case enums::PLAYTYPE::FTMAKE:
						pts = 1;
						break;
					default:
						pts = 0;
				}
				return new Play(trimmedLine, playType, pts, isTeamPlay);
			}
		}
		return nullptr;
	}
	
}

