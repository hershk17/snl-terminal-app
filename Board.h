#ifndef SDDS_BOARD_H
#define SDDS_BOARD_H

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <ctime>

namespace sdds
{
	class Game
	{
		int count,
			roll_no,
			turn_no;

	public:
		void play();
		void start();
		int get_turn() const;
		void next_turn();

		friend class Player;
	};

	class Player
	{
		int position;

	public:
		void move(int, int);
		int get_pos() const;
		void roll(int);

		Player();
	};
}

#endif 
