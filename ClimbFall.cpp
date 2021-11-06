#include "ClimbFall.h"

using namespace std;

namespace sdds
{
	int isSnake(int x)
	{
		switch (x)
		{
		case 16: 
			return 6;
		case 47: 
			return 26;
		case 49: 
			return 11;
		case 56:
			return 53;
		case 62:
			return 19;
		case 64:
			return 60;
		case 87:
			return 24;
		case 93:
			return 73;
		case 95:
			return 75;
		case 98:
			return 78;
		default: 
			return -1;
		}
	}

	int isLadder(int x)
	{
		switch (x)
		{
		case 1:
			return 38;
		case 4:
			return 14;
		case 9:
			return 31;
		case 21:
			return 42;
		case 28:
			return 84;
		case 36:
			return 44;
		case 51:
			return 67;
		case 71:
			return 91;
		case 80:
			return 100;
		default:
			return -1;
		}
	}
}