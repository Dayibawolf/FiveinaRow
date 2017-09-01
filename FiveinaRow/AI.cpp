#include "AI.h"
#include <iostream>
using namespace std;



void AI::computer(Player & player, Chess & chess)
{
	int s = 0;
	sum[0] = 0;
	sum[1] = 0;
	assignscore(sum[s], chess);
	cout << "电脑不会。。。";
}

void AI::assignscore(int sum, Chess & chess)
{
	cout << chess.board[3][4];
	system("pause");
}

int AI::judger(Chess & chess)
{
	sum[0] = 0;
	sum[1] = 0;
	if (chess.count < 9)
	{
		return 0;
	}
	else
	{
		int i, j, s;
		//**********************************************
		//判断横向是否有棋子长连
		s = 0;
		while ( sum[0] < 5 && sum[1] < 5 && s < 2)   
		{
			i = 0;
			j = 0;
			while (sum[s] < 5 && i < 15)
			{
				j = 0;
				while (sum[s] < 5 && j < 15 && sum[s] + (15 - j) >= 5)
				{
					if (chess.board[i][j] == (s + 1))
						sum[s]++;
					else
						sum[s] = 0;
					j++;
				}
				i++;
			}
			s++;
		} 
		//************************************************
		//判断纵向是否有棋子长连
		s = 0;
		while (sum[0] < 5 && sum[1] < 5 && s < 2)   
		{
			i = 0;
			j = 0;
			while (sum[s] < 5 && i < 15)
			{
				j = 0;
				while (sum[s] < 5 && j < 15 && sum[s] + (15 - j) >= 5)
				{
					if (chess.board[j][i] == (s + 1))
						sum[s]++;
					else
						sum[s] = 0;
					j++;
				}
				i++;
			}
			s++;
		}
		//************************************************
		//判断45°是否有棋子长连
		s = 0;
		while (sum[0] < 5 && sum[1] < 5 && s < 2)
		{
			for (int ii = 0; ii < 21; ii++)
			{
				if (ii < 11)
				{
					i = ii + 4;
					j = 0;
					while (sum[s] < 5 && j <= ii+4 )
					{
						if (chess.board[i][j] == (s + 1))
							sum[s]++;
						else
							sum[s] = 0;
						i--;
						j++;
					}
				}
				else
				{
					i = 14;
					j = ii - 10;
					while (sum[s] < 5 && j < 15)
					{
						if (chess.board[i][j] == (s + 1))
							sum[s]++;
						else
							sum[s] = 0;
						i--;
						j++;
					}
				}
				if (sum[s] >= 5) break;
				sum[s] = 0;
			}
			s++;
		}
		//************************************************
		//判断135°是否有棋子长连
		s = 0;
		while (sum[0] < 5 && sum[1] < 5 && s < 2)
		{
			for (int ii = 0; ii < 21; ii++)
			{
				if (ii < 11)
				{
					i = 10 - ii;
					j = 0;
					while (sum[s] < 5 && j <= ii + 4)
					{
						if (chess.board[i][j] == (s + 1))
							sum[s]++;
						else
							sum[s] = 0;
						i++;
						j++;
					}
				}
				else
				{
					i = 0;
					j = ii - 10;
					while (sum[s] < 5 && j < 15)
					{
						if (chess.board[i][j] == (s + 1))
							sum[s]++;
						else
							sum[s] = 0;
						i++;
						j++;
					}
				}
				if (sum[s] >= 5) break;
				sum[s] = 0;
			}
			s++;
		}

		if (sum[0] == 5) return 1;
		else if (sum[1] == 5) return 2;
		else return 0;
	}
}

AI::AI()
{
}


AI::~AI()
{
}
