#include "Chess.h"
#include "Player.h"



bool Chess::istrue(Player & p)
{
	if (!(1 <= p.P_x && p.P_x <= 15 && 1 <= p.P_y && p.P_y <= 15))
		return false;
	else if (board[15 - p.P_x][p.P_y - 1] != 0)
		return false;
	else
		return true;
}

void Chess::putstone(Player & p)
{
	if (p.P_color == "black")
		board[15-p.P_x][p.P_y-1] = 1;
	else
		board[15-p.P_x][p.P_y-1] = 2;
	last_x = 15 - p.P_x;
	last_y = p.P_y - 1;
	count++;
}

Chess::Chess()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = 0;
		}
	}
}


Chess::~Chess()
{
}
