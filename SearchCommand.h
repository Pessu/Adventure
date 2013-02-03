////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
public:
  SearchCommand( Game *pGame ) : Command(pGame) {}
  void Execute()
  {
    if ( rand()%1000 < 436 )
    {
      GoldFactory f;
      Gold *g = f.Create( 1+rand()%100);
      int gg = g->GetAmount();
      GetGame()->SetCurrentGold(g->GetAmount());
      std::ostringstream s;
      s << "You found " << g->GetAmount() << " gold!\n";
      GetGame()->GetRenderer()->Render(s.str());
      if (GetGame()->GetCurrentGold() > 0 && GetGame()->GetCurrentGold() != gg)
  		cout << "You now have " << GetGame()->GetCurrentGold()<< " gold!\n";
      delete g;
    }
    else
    {
      GetGame()->GetRenderer()->Render( "You found nothing.\n");
    }
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
