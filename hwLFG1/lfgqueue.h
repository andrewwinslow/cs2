
#ifndef LFGQUEUE_H
#define LFGQUEUE_H

#include "player.h"

class LFGQueue
{
	public:
		// Constructs a new empty queue
		LFGQueue();

		// Returns the number of players in the queue.
		int size();

		// Pushes a pointer to a player onto the back of the queue.
		void push_player(Player* p);

		// Returns a pointer to the frontmost player 
		// with the specified role. 
		// If no such player exists, returns nullptr.
		Player* front_player(Player::Role r);

		// Removes the frontmost player with the specified role. 
		// If no such player exists, does nothing.
		void pop_player(Player::Role r);	

		// Returns whether the queue contains a complete group
		// (a Defender, a Hunter, and a Bard).
		//
		// If the queue contains a complete group, the method
		// sets the first three elements of the array parameter
		// equal to the addresses of the frontmost:
		// 1. Defender (index 0)
		// 2. Hunter (index 1)
		// 3. Bard (index 2)
		bool front_group(Player** group);

		// Removes the frontmost Defender, Hunter, and Bard 
		// from the queue. If some role has no player with that role, 
		// then does nothing.
		void pop_group();

	private:
		Player** players;
		int count;
		int capacity;
};

#endif

