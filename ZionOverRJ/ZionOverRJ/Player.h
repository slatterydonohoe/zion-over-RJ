//
//  Player.hpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <string>
#include "Play.h"
#include <vector>
#include "Possession.h"

class Player
{
public:
	Player(std::string name);
	std::string getName();
	void addPossession(Possession* p);
//private:
	std::string m_name;
	std::vector<Possession*>* m_offensivePossessionsOnCourt;
	std::vector<Possession*>* m_offensivePossessionsOffCourt;
	std::vector<Possession*>* m_defensivePossessionsOnCourt;
	std::vector<Possession*>* m_defensivePossessionsOffCourt;
};

#endif /* Player_h */
