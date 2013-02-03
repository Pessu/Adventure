////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "GoldFactory.h"
#include "Gold.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
Gold * GoldFactory::Create( size_t amount)
{
  // New object for this search
  Gold * pGoldFound = new Gold(amount);
  // Add this search into totals
  *pGoldTotal = (*pGoldTotal + *pGoldFound);

 // std::cout << "Gold Found " << pGoldFound->GetAmount() << endl;

  // Prints total booty
  //std::cout << "Total loot " << pGoldTotal->GetAmount() << " gold!" <<endl;


  //totals.push_back(pGoldTotal);
  /*
  for(it = totals.begin(); it != totals.end(); ++it)
  {
	  Gold *g = *it;
	  cout << g->GetAmount();
  }
  */
  return pGoldFound;
}
////////////////////////////////////////////////////////////////////////////////
