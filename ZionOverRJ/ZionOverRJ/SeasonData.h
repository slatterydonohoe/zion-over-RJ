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
#include "Play.h"
#include "Possession.h"
class SeasonData
{
public:
	SeasonData(std::vector<Play*>* playData);
	
private:
	void findEndsOfPossessions();
	void populatePossessions();
	std::vector<Play*>* m_playData;
	std::vector<Possession*>* m_possessionData;
};

#endif /* SeasonData_h */
