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

class Gold;
////////////////////////////////////////////////////////////////////////////////
class GoldFactory
{
public:
  Gold * Create( size_t amount);
  Gold * pGoldTotal;
};
////////////////////////////////////////////////////////////////////////////////
#endif