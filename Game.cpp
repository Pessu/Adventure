////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "Game.h"
#include "Player.h"
#include "GoldFactory.h"
#include "Gold.h"
#include "QuitCommand.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "TextRenderer.h"
#include <sstream>
#include "IRenderer.h"
#include "CommandFactory.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "Chambers.h"
#include "globals.h"
#include "time.h"
#include "Gold.h"
#include <list>
#include <algorithm>
//#include <signal.h>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define DEV_NAME "anssi.grohn@pkamk.fi"
#define YEAR 2011

////////////////////////////////////////////////////////////////////////////////
Game::Game() :
		running(true)
{
	currentGold = 0;

	renderer = new TextRenderer();

	rooms.push_back(new Dungeon());
	rooms.at(0)->SetGame(this);
	rooms.push_back(new Hallway());
	rooms.at(1)->SetGame(this);
	rooms.push_back(new MonsterRoom());
	rooms.at(2)->SetGame(this);
	rooms.push_back(new Chambers());
	rooms.at(3)->SetGame(this);

	rooms.at(0)->SetNextRoom(North, rooms.at(1));
	rooms.at(1)->SetNextRoom(South, rooms.at(0));
	rooms.at(1)->SetNextRoom(North, rooms.at(2));
	rooms.at(2)->SetNextRoom(South, rooms.at(1));
	rooms.at(2)->SetNextRoom(North, rooms.at(3));
	rooms.at(3)->SetNextRoom(South, rooms.at(2));

	currentRoom = rooms.at(0);

	/*
	 rooms[kDungeon] = new Dungeon();
	 rooms[kDungeon]->SetGame(this);
	 rooms[kHallway] = new Hallway();
	 rooms[kHallway]->SetGame(this);
	 rooms[kMonster] = new MonsterRoom();
	 rooms[kMonster]->SetGame(this);
	 rooms[kChambers] = new Chambers();
	 rooms[kChambers]->SetGame(this);

	 rooms[kDungeon]->SetNextRoom(North,rooms[kHallway]);
	 rooms[kHallway]->SetNextRoom(South,rooms[kDungeon]);
	 rooms[kHallway]->SetNextRoom(North,rooms[kMonster]);
	 rooms[kMonster]->SetNextRoom(South,rooms[kHallway]);
	 rooms[kMonster]->SetNextRoom(North,rooms[kChambers]);
	 rooms[kChambers]->SetNextRoom(South,rooms[kMonster]);
	 */
}
////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{

}
////////////////////////////////////////////////////////////////////////////////
void Game::Play()
{
	string cmd;
	renderer->Render("Welcome to Fiends'n'Frogs adventure game!\n");

	ostringstream s;
	s << "by " << DEV_NAME << "(c) " << YEAR << ". Licensed under GPLv3.\n";
	renderer->Render(s.str());
	Player::AskInfo(player);
	renderer->Render("\nPlayer statistics:\n\n");
	player.PrintSummary();
	renderer->Render("\nAnd behold, the adventure begins!\n");

	player.SetGame(this);

	srand(time(NULL));
	while (running)
	{

		renderer->Render(GetCurrentRoom()->GetDescription());
		renderer->Render("\n> ");

		getline(cin, cmd);

		CommandFactory comm(this);
		ICommand *pCommand = comm.Create(cmd);
		if (pCommand)
			pCommand->Execute();

		//delete pCommand;

		GetCurrentRoom()->Update();

		if (player.GetHitpoints() <= 0)
		{

			renderer->Render("You're dead. Game over.\n");
			running = false;
		}
	}
	// final message to player
	renderer->Render("Exiting, bye!\n");
}
////////////////////////////////////////////////////////////////////////////////
void Game::SetRenderer(IRenderer *pRenderer)
{
	renderer = pRenderer;
}
////////////////////////////////////////////////////////////////////////////////
IRenderer *
Game::GetRenderer() const
{
	return renderer;
}
////////////////////////////////////////////////////////////////////////////////
bool Game::IsRunning() const
{
	return running;
}
////////////////////////////////////////////////////////////////////////////////
void Game::SetRunning(bool bFlag)
{
	running = bFlag;
}
////////////////////////////////////////////////////////////////////////////////
Player &
Game::GetPlayer()
{
	return player;
}
////////////////////////////////////////////////////////////////////////////////

Room *
Game::GetCurrentRoom()
{
	return currentRoom;
}
////////////////////////////////////////////////////////////////////////////////
void Game::SetCurrentRoom(Room *pRoom)
{
	currentRoom = pRoom;
}
void Game::SetCurrentGold(int gold)
{
	goldTotal.push_back(gold);
}
int Game::GetCurrentGold()
{
	// Old way of doing this
	/*
	int sum = 0;
	for (it = goldTotal.begin(); it!=goldTotal.end();it++)
	{
	sum +=*it;
	}
	*/

	// A for_each algorithm that uses a functor to sum the elements
	int total = 0;
	vectorSum sum(&total);
	for_each(goldTotal.begin(), goldTotal.end(), sum);


	// Alternative way to do it with a shorter local lambda function
	/*
	auto total = 0;
	for_each(goldTotal.begin(), goldTotal.end(), [&](int n){total += n;});
	*/

	// Another even more "elegant" way to do this with a range-based for loop
	/*
	auto total = 0;
	for (auto i : goldTotal)
	{
		total+=i;
	}
	*/

	// Getting the most valuable search, doesn't make much sense with pure gold but if I were to change
	// Gold into objects (sets i.g) with name and value it would.
	/*
	it = max_element(goldTotal.begin(), goldTotal.end());
	int mostValuableObject = *it;
	*/

	return total /*total*/;
}
////////////////////////////////////////////////////////////////////////////////

