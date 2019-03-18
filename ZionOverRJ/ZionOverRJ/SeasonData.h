//
//  SeasonData.hpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/17/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef SeasonData_h
#define SeasonData_h

#include <stdio.h>
#include <vector>
#include "Play.h"
#include "Possession.h"
#include "Player.h"

class SeasonData
{
public:
	SeasonData(std::vector<Play*>* playData);
	
	
private:
	void findEndsOfPossessions();
	void populatePossessions();
	void organizePlayerData();
	
	std::vector<Play*>* m_playData;
	std::vector<Possession*>* m_possessionData;
	
	Player* m_Zion;
	Player* m_RJ;
};

#endif /* SeasonData_h */
