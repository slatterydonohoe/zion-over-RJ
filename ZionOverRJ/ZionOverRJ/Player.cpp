//
//  Player.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include "Player.h"

Player::Player(std::string name) :
m_name(name)
{
	m_offensivePossessionsOnCourt = new std::vector<Possession*>();
	m_offensivePossessionsOffCourt = new std::vector<Possession*>();
	m_defensivePossessionsOnCourt = new std::vector<Possession*>();
	m_defensivePossessionsOffCourt = new std::vector<Possession*>();
}

std::string Player::getName()
{
	return m_name;
}

void Player::addPossession(Possession* p)
{
	if (p->getLineupText().find(m_name) != std::string::npos)
	{
		if (p->getTeamPlay()) {
			m_offensivePossessionsOnCourt->push_back(p);
		}
		else{
			m_defensivePossessionsOnCourt->push_back(p);
		}
	}
	else
	{
		if (p->getTeamPlay()) {
			m_offensivePossessionsOffCourt->push_back(p);
		}
		else{
			m_defensivePossessionsOffCourt->push_back(p);
		}
	}
}
