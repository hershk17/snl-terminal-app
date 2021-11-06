#ifndef SDDS_VISUAL_H
#define SDDS_VISUAL_H

#include "Board.h"
#include "ClimbFall.h"

namespace sdds
{
	void borders();
	void erase(int = 4, int = 30);
	void gotoxy(int, int);
	void icon(const char[], int, int);
}

#endif

