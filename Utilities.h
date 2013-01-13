/*
 * Utilities.h
 *
 *  Created on: 21.12.2012
 *      Author: Pessu
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <string>
#include "Player.h"

using namespace std;

class Utilities
{
public:
	Utilities();
	//Player * player;
	bool SavePlayer(Player & player);
	typedef struct retuned_array
	{
		string statsArray[30];
	} statsStruct;
	statsStruct LoadPlayer();
	int convertStringToInt(string par1);

	virtual ~Utilities();
};

#endif /* UTILITIES_H_ */
