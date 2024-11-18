#include <exception>
using namespace std;

#ifndef __Knight_h__
#define __Knight_h__

#include "Champion.h"
#include "Actions.h"

namespace character
{
	// class Champion;
	// __interface Actions;
	class Knight;
}

namespace character
{
	class Knight: public character::Champion, public character::Actions
	{
		private: int _shield;

		public: void getInfo();

		public: void attack(character::Champion& aOther);

		public: void takeDame(string aInt_damage);
	};
}

#endif
