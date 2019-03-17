//
//  PlayByPlayParse.h
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef PlayByPlayParse_h
#define PlayByPlayParse_h

#include <stdio.h>
#include <string>
#include <fstream>
#include "Play.h"
#include <vector>
#include <map>

class PlayByPlayParse
{
public:
	PlayByPlayParse();
	std::vector<Play*>* parseFile(std::ifstream* infile);
	
private:
	Play* parseLine(std::string line);
	std::map<enums::PLAYER, const char *> m_playerNames;
	std::map<enums::PLAYTYPE, const char *> m_playTypes;
};

#endif /* PlayByPlayParse_h */
