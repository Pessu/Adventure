/*
 * SaveCommand.cpp
 *
 *  Created on: 20.12.2012
 *      Author: Pessu
 */

#include "SaveCommand.h"
#include "Game.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Utilities.h"
void SaveCommand::Execute()
{
	if (SavePlayer(GetGame()->GetPlayer()))
			std::cout<<"Game Saved!\n";
}
