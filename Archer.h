#include <exception>
using namespace std;

#ifndef __Archer_h__
#define __Archer_h__

#include "Champion.h"
#include "Actions.h"

namespace character
{
	// class Champion;
	// __interface Actions;
	class Archer;
}

namespace character
{
	class Archer: public character::Champion, public character::Actions
	{
		private: int _accuracy;

		public: void getInfo();

		public: void attack(character::Champion& aOther);

		public: void takeDame(string aInt_damage);
	};
}

#endif
