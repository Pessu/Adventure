////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __MonsterRoom_h__
#define __MonsterRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
#include <vector>
////////////////////////////////////////////////////////////////////////////////
class MonsterRoom : public Room
{
private:
  vector <Enemy> enemy;
  Enemy e;
  bool noticedPlayer;
public:
  MonsterRoom()
  {
    noticedPlayer = false;
    enemy.push_back(e);
    enemy.at(0).SetName("Goblin");
    SetDescription("You are in the monster room. There is a goblin here!");
  }
  ////////////////////
  /// Makes enemy attack player once on every turn.
  void Update()
  {
    if ( enemy.at(0).IsAlive() && noticedPlayer )
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << enemy.at(0).GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      enemy.at(0).Attack(&player);
    }
    noticedPlayer = true;
  }
  ////////////////////
  /// Restricts movement until enemy is killed.
  /// \param pCommand Move command.
  /// \return Room pointer to next available room, NULL if none available.
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
    if ( enemy.at(0).IsAlive())
    {
      return NULL;
    }
    else
      return GetNextRoom( pCommand->GetDirection() );
  }
  
  void OnAttack( AttackCommand *pCommand )
  {
    if ( enemy.at(0).IsAlive() && noticedPlayer)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << enemy.at(0).GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack(&enemy.at(0));
      // Change room description a bit
      if ( enemy.at(0).IsAlive() == false )
      {
    	  noticedPlayer = false;
    	  player.SetExperience(player.GetExperience()+1);
    	  SetDescription("You are in the monster room. There is a jolly dead goblin here.");
      }
    } 
    else 
    {
      // to encourage player to stop beating it further
      GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
    }

  }

};
////////////////////////////////////////////////////////////////////////////////
#endif



