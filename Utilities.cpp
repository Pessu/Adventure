/*
 * Utilities.cpp
 *
 *  Created on: 21.12.2012
 *      Author: Pessu
 */

#include "Utilities.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "Exceptions.h"
#include "Game.h"
#include "Player.h"
using namespace std;

//class Player;
Utilities::Utilities()
{

}

Utilities::~Utilities()
{

}

int isNumeric(char* str)
{
    int len = strlen(str);
    int i = 0;
    int ret = 1;
    int deccnt = 0;
    while(i < len && ret != 0)
    {
        if(str[i] == '.')
        {
            deccnt++;
            if(deccnt > 1)
                ret = 0;
        }
        else
            ret = isdigit(str[i]);
        i++;
    }
    return ret;
}


int Utilities::convertStringToInt(string par1)
{
	int result = atoi(par1.c_str());
	return result;
}

Utilities::statsStruct Utilities::LoadPlayer()
{
	statsStruct result;
	string str;

	ifstream instream;
	instream.open("PlayerInfo.bin", ios::in);
	int i = 0;

	if (instream.is_open())
	{
		while(!instream.eof())
		{
			getline (instream,result.statsArray[i],'\n');
			i++;
		}
		instream.close();
	}
	else
	{
		throw (FileNotFoundException("File error, could not load"));
	}

	return result;
}

bool Utilities::SavePlayer(Player & player)
{
	ofstream outstream("PlayerInfo.bin", ios::out | ios::trunc);
	if (outstream)
	{
		outstream << player.GetName() << endl;
		outstream << player.GetAge() << endl;
		outstream << player.GetRace() << endl;
		outstream << player.GetGender() << endl;
		outstream << player.GetClass() << endl;
		outstream << player.GetExperience() << endl;
		outstream << player.GetHitpoints() << endl;

		outstream.close();
		return true;
	}
	else
	{
		throw (FileNotFoundException("File error, could not save"));
	}

}

