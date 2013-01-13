/*
 * LoadCommand.h
 *
 *  Created on: 20.12.2012
 *      Author: Pessu
 */

#ifndef LOADCOMMAND_H_
#define LOADCOMMAND_H_

class Game;
#include "Command.h"
#include "Utilities.h"

class LoadCommand : public Command, public Utilities
{
public:
	LoadCommand( Game *pGame ) : Command(pGame) { }
	void Execute();
};
#endif /* LOADCOMMAND_H_ */
