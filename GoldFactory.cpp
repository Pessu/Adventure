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
  // Prints total booty
  std::cout << "Total loot -> " << pGoldTotal->GetAmount() << endl;

  return pGoldFound;
}
////////////////////////////////////////////////////////////////////////////////
