//
//  main.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include <iostream>
#include "PlayByPlayParse.h"

int main(int argc, const char * argv[]) {
	PlayByPlayParse* parser = new PlayByPlayParse();
	std::ifstream infile("/Users/slatterydonohoe/Documents/PersonalProjects/zion-over-RJ/ZionOverRJ/ZionOverRJ/testSheet.csv");
	std::vector<Play*>* plays = parser->parseFile(&infile);
	return 0;
}
