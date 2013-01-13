/*
 * SaveCommand.h
 *
 *  Created on: 20.12.2012
 *      Author: Pessu
 */

#ifndef SAVECOMMAND_H_
#define SAVECOMMAND_H_

class Game;
#include "Command.h"
#include "Utilities.h"

class SaveCommand  : public Command, public Utilities
{
public:
  SaveCommand( Game *pGame ) : Command(pGame) { }

  void Execute();

};
#endif /* SAVECOMMAND_H_ */
