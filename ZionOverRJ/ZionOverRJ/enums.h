//
//  enums.h
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#ifndef enums_h
#define enums_h

#include <stdio.h>
#include <string>

namespace enums
{
	enum PLAYTYPE
	{
		NOPLAY = 0,
		DRB,
		ORB,
		FGMAKE,
		FGMISS,
		FTMAKE,
		FTMISS,
		SHFOUL,
		PFOUL,
		OFOUL,
		TOV,
		LINEUP
	};
	
	enum PLAYER
	{
		BARRETT,
		JONES,
		BOLDEN,
		REDDISH,
		WILLIAMSON,
		WHITE,
		DELAURIER,
		OCONNELL,
		GOLDWIRE,
		VRANKOVIC,
		ROBINSON,
		BESSER,
		BUCKMIRE,
		BAKER
	};
}

#endif /* enums_h */
