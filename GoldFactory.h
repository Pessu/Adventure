////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __GoldFactory_h__
#define __GoldFactory_h__
////////////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <list>
#include <vector>
using namespace std;
class Gold;
////////////////////////////////////////////////////////////////////////////////
class GoldFactory
{
public:
  Gold * Create( size_t amount);
  Gold * pGoldTotal;

  //vector <Gold*> totals;
  //vector<Gold*>::iterator it;

};
////////////////////////////////////////////////////////////////////////////////
#endif
