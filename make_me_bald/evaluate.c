#include "const.h"

//带有_p则代表玩家的排序

//局势评分
int evaluate(char sequance[][16])
{
	int score = 0;
	//100000分
	char chenwu[5] = { computer_color,computer_color,computer_color,computer_color,computer_color };

	char chenwu_p[5] = { player_color,player_color, player_color, player_color, player_color };
	//10000分
	char huosi1[6] = { empty,computer_color,computer_color,computer_color,computer_color,empty };
	char huosi2[5] = { computer_color,empty,computer_color,computer_color,computer_color };
	char huosi3[5] = { computer_color,computer_color,empty,computer_color,computer_color };
	char huosi4[5] = { computer_color,computer_color,computer_color,empty,computer_color };

	char huosi1_p[6] = { empty,player_color,player_color,player_color,player_color,empty };
	char huosi2_p[5] = { player_color,empty,player_color, player_color, player_color };
	char huosi3_p[5] = { player_color,player_color,empty,player_color, player_color };
	char huosi4_p[5] = { player_color,player_color,player_color,empty,player_color };
	//1000分
	char sisi1[6] = { empty,computer_color,computer_color,computer_color,computer_color,player_color };
	char sisi2[6] = { player_color,computer_color,computer_color,computer_color,computer_color,empty };
	char huosan1[5] = { empty,computer_color,computer_color,computer_color,empty };
	char huosan2[6] = { empty,computer_color,empty,computer_color,computer_color,empty };
	char huosan3[6] = { empty,computer_color,computer_color,empty,computer_color,empty };

	char sisi1_p[6] = { empty,player_color,player_color,player_color,player_color,computer_color };
	char sisi2_p[6] = { computer_color,player_color,player_color,player_color,player_color,empty };
	char huosan1_p[5] = { empty,player_color,player_color,player_color,empty };
	char huosan2_p[6] = { empty,player_color,empty,player_color,player_color,empty };
	char huosan3_p[6] = { empty,player_color,player_color,empty,player_color,empty };
	//100分
	char sisan1[5] = { empty,computer_color,computer_color,computer_color,player_color };
	char sisan2[5] = { player_color,computer_color,computer_color,computer_color,empty };
	char huoer1[4] = { empty,computer_color,computer_color,empty };
	char huoer2[5] = { empty,computer_color,empty,computer_color,empty };

	char sisan1_p[5] = { empty,player_color,player_color,player_color,computer_color };
	char sisan2_p[5] = { computer_color,player_color,player_color,player_color,empty };
	char huoer1_p[4] = { empty,player_color,player_color,empty };
	char huoer2_p[5] = { empty,player_color,empty,player_color,empty };
	//10分
	char sier1[4] = { empty,computer_color,computer_color,player_color };
	char sier2[4] = { player_color,computer_color,computer_color,empty };
	char huoyi[3] = { empty,computer_color,empty };

	char sier1_p[4] = { empty,player_color,player_color,computer_color };
	char sier2_p[4] = { computer_color,player_color,player_color,empty };
	char huoyi_p[3] = { empty,player_color,empty };
	//*********************************************************************************
	for (int i = 0; i <= 72; i++)
	{
		//100000
		score += (100000 * find(sequance[i], chenwu, 5));

		score -= (500000 * find(sequance[i], chenwu_p, 5));
		//10000
		score += (10000 * find(sequance[i], huosi1, 6));
		score += (10000 * find(sequance[i], huosi2, 5));
		score += (10000 * find(sequance[i], huosi3, 5));
		score += (10000 * find(sequance[i], huosi4, 5));

		score -= (50000 * find(sequance[i], huosi1_p, 6));
		score -= (50000 * find(sequance[i], huosi2_p, 5));
		score -= (50000 * find(sequance[i], huosi3_p, 5));
		score -= (50000 * find(sequance[i], huosi4_p, 5));
		//1000
		score += (1000 * find(sequance[i], sisi1, 6));
		score += (1000 * find(sequance[i], sisi2, 6));
		score += (1000 * find(sequance[i], huosan1, 5));
		score += (1000 * find(sequance[i], huosan2, 6));
		score += (1000 * find(sequance[i], huosan3, 6));

		score -= (5000 * find(sequance[i], sisi1_p, 6));
		score -= (5000 * find(sequance[i], sisi2_p, 6));
		score -= (5000 * find(sequance[i], huosan1_p, 5));
		score += (5000 * find(sequance[i], huosan2_p, 6));
		score += (5000 * find(sequance[i], huosan3_p, 6));
		//100
		score += (100 * find(sequance[i], sisan1, 5));
		score += (100 * find(sequance[i], sisan2, 5));
		score += (100 * find(sequance[i], huoer1, 4));
		score += (100 * find(sequance[i], huoer2, 5));

		score -= (500 * find(sequance[i], sisan1_p, 5));
		score -= (500 * find(sequance[i], sisan2_p, 5));
		score -= (500 * find(sequance[i], huoer1_p, 4));
		score -= (500 * find(sequance[i], huoer2_p, 5));
		//10
		score += (10 * find(sequance[i], sier1, 4));
		score += (10 * find(sequance[i], sier2, 4));
		score += (10 * find(sequance[i], huoyi, 3));

		score -= (50 * find(sequance[i], sier1_p, 4));
		score -= (50 * find(sequance[i], sier2_p, 4));
		score -= (50 * find(sequance[i], huoyi_p, 3));
	}
	return score;
}
