#include <exception>
#include <string>
using namespace std;

#ifndef __ChampionInterface_h__
#define __ChampionInterface_h__

#include "Champion.h"

namespace character
{
	// class Champion;
	class ChampionInterface;
}

namespace character
{
	class ChampionInterface
	{

		public: virtual void attack(character::Champion& aOther) = 0;

		public: virtual void takeDamage(string aInt_damge) = 0;

		public: virtual string getInfo() = 0;

		public: void attack(character::Champion& aOther);

		public: void takeDamage(string aInt_damge);

		public: string getInfo();
	};
}

#endif
