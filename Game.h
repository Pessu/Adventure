////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Game_h__
#define __Game_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer;
class Room;
////////////////////////////////////////////////////////////////////////////////
enum RoomId
{
	kDungeon, kHallway, kMonster, kChambers, kNumRooms
};
#include "Player.h"
#include "Enemy.h"
#include <list>
#include <vector>
////////////////////////////////////////////////////////////////////////////////
class Game
{
private:
	bool running;
	Player player;
	IRenderer *renderer;
	//Room      *rooms[kNumRooms]; ///< Map.
	vector<Room*> rooms;
	Room *currentRoom;
public:

	struct vectorSum
	{
		vectorSum(int * t) :total(t){};
		int * total;

		void operator()(int element)
		{
			*total += element;
		}
	};

	vector<int> goldTotal;
	vector<int>::iterator it;
	int currentGold;
	Game();
	virtual ~Game();
	void Play();
	void SetRenderer(IRenderer *pRenderer);
	IRenderer * GetRenderer() const;
	bool IsRunning() const;
	void SetRunning(bool bFlag);
	Player & GetPlayer();
	Room * GetCurrentRoom();
	void SetCurrentRoom(Room *pRoom);
	void SetCurrentGold(int gold);
	int GetCurrentGold();
};
////////////////////////////////////////////////////////////////////////////////
#endif
