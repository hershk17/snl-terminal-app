#include "Board.h"
#include "ClimbFall.h"
#include "visual.h"

using namespace std;

namespace sdds
{
	void Game::start()
	{
		turn_no = 1;

		gotoxy(12, 12);
		cout << "Press any key to start.";
		_getch();

		this->play();
	}

	void Game::play()
	{
		Player P1, P2;
		int who;
		srand((unsigned)time(0));

		while (P1.get_pos() <= 100 && P2.get_pos() <= 100) {
			erase(12);
			who = get_turn();
			gotoxy(9, 6);
			cout << "Playing Now:         Position:";
			gotoxy(9, 7);
			cout << "  Player " << who;

			gotoxy(33, 7);

			if (who == 1) {
				cout << P1.get_pos();
				P1.roll(1);
			}
			else {
				cout << P2.get_pos();
				P2.roll(2);
			}
			_getch();

			next_turn();
		}
	}

	int Player::get_pos() const
	{
		return position;
	}

	int Game::get_turn() const
	{
		return turn_no;
	}

	void Game::next_turn()
	{
		if (turn_no == 1) {
			turn_no++;
		}
		else {
			turn_no--;
		}
	}

	void Player::roll(int x)
	{
		int no = -1;
		char c;

		for (;;) {
			gotoxy(12, 26);
			cout << "Press spacebar to roll.";

			do
			{
				c = _getch();

				if (c == ' ') {
					no = rand() % 6 + 1;
					gotoxy(16, 15);
					cout << "You rolled a " << no << ".";

					move(no, x);
					erase(24);
				}
			} while (c != ' ');

			if (no == 6) {
				gotoxy(18, 24);
				cout << "Roll again!";
			}
			else {
				gotoxy(11, 26); 
				cout << "Press any key to continue."; 
				break;
			}
		}
	}

	void Player::move(int n, int x)
	{
		int s_result, 
			l_result, 
			new_pos = position + n;

		if (x == 1) {
			icon("P1", position, new_pos);
		}
		else {
			icon("P2", position, new_pos);
		}

		if (new_pos <= 100) {
			s_result = isSnake(new_pos);
			l_result = isLadder(new_pos);
			
			_getch();

			if (s_result != -1) {
				gotoxy(13, 17); 
				cout << "SNAKE!!! Fell to " << s_result << "..." ;
				position = s_result;
			}
			else
				if (isLadder(new_pos) != -1) {
					gotoxy(11, 17); 
					cout << "LADDER!!! Climbed to " << l_result << "...";
					position = l_result;
				}
				else {
					gotoxy(17, 17); 
					cout << "Moved to " << new_pos << "...";
					position = new_pos;
				}
			if (x == 1) {
				icon("P1", new_pos, position);
			}
			else {
				icon("P2", new_pos, position);
			}

			gotoxy(33, 7);
			cout << position << "    ";

			if (position == 100) {
				erase(13);
				gotoxy(18,20);
				cout << "You win!!!!!!!";
				gotoxy(14, 20);
				cout << "Press any key to exit.";
				_getch();
				_Exit(10);
			}
		}
		else {
			cout << ", can't move!!! (can't cross 100)";
		}
			
	}

	Player::Player()
	{
		position = 0;
	}
}