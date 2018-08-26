
#ifndef LFGQUEUE_H
#define LFGQUEUE_H

#include "player.h"

class LFGQueue 
{
	public:
		// All of the methods are the same 
		// as in hwLFG1.
		LFGQueue();

		int size();
		void push_player(Player* p);

		Player* front_player(Player::Role r);
		void pop_player(Player::Role r);	

		bool front_group(Player** group);
		void pop_group();

	private:
		class Node
		{
			public:
				Player* p;
				Node* next;
		};

                // You can index into these arrays using Player::Role values!
                // Check out player.h to see the int value of each Role.
                //
                // This lets you do things like:
                // "if (heads[p->role()] == nullptr)" and "++counts[p->role()]" 
		Node* heads[3];
		Node* tails[3];
		int counts[3];
};

#endif


