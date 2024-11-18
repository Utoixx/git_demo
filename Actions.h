#include <exception>
using namespace std;

#ifndef __Actions_h__
#define __Actions_h__

#include "Champion.h"

namespace character
{
	class Champion;
	__interface Actions;
}

namespace character
{
	__interface Actions
	{

		public: virtual void getInfo() = 0;

		public: virtual void attack(character::Champion& aOther) = 0;

		public: virtual void takeDame(string aInt_damage) = 0;
	};
}

#endif
