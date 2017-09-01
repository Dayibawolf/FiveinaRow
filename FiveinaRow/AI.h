#pragma once
#include "Player.h"
#include "Chess.h"
#include <string>
class AI
{
private:
	int sum[2];
	int score[15][15];
public:
	void computer(Player &player, Chess &chess);
	void assignscore(int sum, Chess &chess);
	int judger(Chess &chess);
	AI();
	~AI();
};

