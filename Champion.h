#include <exception>
#include <string>
using namespace std;

#ifndef __Champion_h__
#define __Champion_h__

namespace character
{
	class Champion;
}

namespace character
{
	class Champion
	{
		private: string _name;
		private: int _hP;
		private: int _damage;

		public: Champion(string aName, string aInt_HP, string aInt_damage);

		public: void isAlive();
	};
}

#endif
