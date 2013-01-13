/*
 * LoadCommand.cpp
 *
 *  Created on: 20.12.2012
 *      Author: Pessu
 */

#include "LoadCommand.h"
#include "Game.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "Utilities.h"
#include <istream>
#include <string>
#include "GameObject.h"

void LoadCommand::Execute()
{
	statsStruct stats;
	stats = LoadPlayer();
	int i;

	GetGame()->GetPlayer().SetName(stats.statsArray[0]);
	GetGame()->GetPlayer().SetRace(stats.statsArray[1]);
	i = convertStringToInt(stats.statsArray[2]);
	GetGame()->GetPlayer().SetAge(i);
	i = convertStringToInt(stats.statsArray[3]);
	GetGame()->GetPlayer().SetGender((i == 1 ? Male : Female));
	i = convertStringToInt(stats.statsArray[4]);
	GetGame()->GetPlayer().SetClass((Class)i);
	i = convertStringToInt(stats.statsArray[5]);
	GetGame()->GetPlayer().SetExperience(i);
	i = convertStringToInt(stats.statsArray[6]);
	GetGame()->GetPlayer().SetHitpoints(i);

	std::cout<<"Game Loaded!\n";
}
