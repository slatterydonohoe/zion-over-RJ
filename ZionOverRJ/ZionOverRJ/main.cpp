//
//  main.cpp
//  ZionOverRJ
//
//  Created by Slattery Donohoe on 3/15/19.
//  Copyright © 2019 Slattery Donohoe. All rights reserved.
//

#include <iostream>
#include "PlayByPlayParse.h"
#include "SeasonData.h"

int main(int argc, const char * argv[]) {
	std::string files[] = {
		"army_plays.txt",
		"auburn_plays.txt",
		"bc_plays.txt",
		"clemson_plays.txt",
		"cuse_plays.txt",
		"cuse2_plays.txt",
		"cuse3_plays.txt",
		"emich_plays.txt",
		"fsu_plays.txt",
		"fsu2_plays.txt",
		"indiana_plays.txt",
		"kentucky_plays.txt",
		"gt_plays.txt",
		"hartford_plays.txt",
		"louisville_plays.txt",
		"miami_plays.txt",
		"msu_plays.txt",
		"ncstate_plays.txt",
		"ndsu_plays.txt",
		"pitt_plays.txt",
		"princeton_plays.txt",
		"stetson_plays.txt",
		"stjohns_plays.txt",
		"sdsu_plays.txt",
		"texastech_plays.txt",
		"unc3_plays.txt",
		"ucf_plays.txt",
		"unc_plays.txt",
		"uva_plays.txt",
		"unc2_plays.txt",
		"uva2_plays.txt",
		"vt_plays.txt",
		"vt2_plays.txt",
		"wake2_plays.txt",
		"yale_plays.txt",
		"wake_plays.txt",
		"zaga_plays.txt"
	};
	PlayByPlayParse* parser = new PlayByPlayParse();
	std::string filepath = "/Users/slatterydonohoe/Documents/PersonalProjects/zion-over-RJ/data/";
	std::vector<Play*> plays;
	for (auto file : files) {
		std::string filename = filepath + file;
		std::ifstream infile(filename.c_str());
		std::vector<Play*>* filePlays = parser->parseFile(&infile);
		for (auto play : *filePlays) {
			plays.push_back(play);
		}
	}
	SeasonData* data = new SeasonData(&plays);
	
	return 0;
}
