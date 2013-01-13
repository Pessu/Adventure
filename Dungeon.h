////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
#ifndef __Dungeon_h__
#define __Dungeon_h__
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
#include "IRenderer.h"
#include "Game.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
#include "MonsterRoom.h"
class Dungeon : public Room
{
private:

public:
  MonsterRoom h;
  Dungeon()
  {

    SetDescription("You are locked up in a dungeon.");
    h.alreadyVisited = true;
  }
  void Update()
  {
	  if (h.alreadyVisited)
		std::cout<<"This place seems familiar. ";
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
