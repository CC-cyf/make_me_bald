#include "const.h"

//带有_p则代表玩家的排序
//100000分
char chenwu[5] = {black, black, black, black, black};

char chenwu_p[5] = {white, white, white, white, white};
//10000分
char huosi1[6] = { empty, black, black, black, black, empty };
char huosi2[7] = { empty,black, empty, black, black, black, empty };
char huosi3[7] = { empty,black, black, empty, black, black, empty };
char huosi4[7] = { empty,black, black, black, empty, black, empty };

char huosi1_p[6] = { empty, white, white, white, white, empty };
char huosi2_p[7] = { empty,white, empty, white, white, white,empty };
char huosi3_p[7] = { empty,white, white, empty, white, white,empty };
char huosi4_p[7] = { empty,white, white, white, empty, white,empty };
//1000分
char sisi1[6] = {empty, black, black, black, black, white};
char sisi2[6] = {white, black, black, black, black, empty};
char sisi3[7] = { white,black, empty, black, black, black, empty };
char sisi4[7] = { white,black, black, empty, black, black, empty };
char sisi5[7] = { white,black, black, black, empty, black, empty };
char sisi6[7] = { empty,black, empty, black, black, black, white };
char sisi7[7] = { empty,black, black, empty, black, black, white };
char sisi8[7] = { empty,black, black, black, empty, black, white };
char huosan1[5] = {empty, black, black, black, empty};
char huosan2[6] = {empty, black, empty, black, black, empty};
char huosan3[6] = {empty, black, black, empty, black, empty};
char huosan4[6] = { empty, black, empty, black, black, white };
char huosan5[6] = { white, black, black, empty, black, empty };

char sisi1_p[6] = {empty, white, white, white, white, black};
char sisi2_p[6] = {black, white, white, white, white, empty};
char sisi3_p[7] = { black,white, empty, white, white, white,empty };
char sisi4_p[7] = { black,white, white, empty, white, white,empty };
char sisi5_p[7] = { black,white, white, white, empty, white,empty };
char sisi6_p[7] = { empty,white, empty, white, white, white,black };
char sisi7_p[7] = { empty,white, white, empty, white, white,black };
char sisi8_p[7] = { empty,white, white, white, empty, white,black };
char huosan1_p[5] = {empty, white, white, white, empty};
char huosan2_p[6] = {empty, white, empty, white, white, empty};
char huosan3_p[6] = {empty, white, white, empty, white, empty};
char huosan4_p[6] = { empty, white, empty, white, white, black };
char huosan5_p[6] = { black, white, white, empty, white, empty };
//100分
char sisan1[5] = {empty, black, black, black, white};
char sisan2[5] = {white, black, black, black, empty};
char huoer1[4] = {empty, black, black, empty};
char huoer2[5] = {empty, black, empty, black, empty};

char sisan1_p[5] = {empty, white, white, white, black};
char sisan2_p[5] = {black, white, white, white, empty};
char huoer1_p[4] = {empty, white, white, empty};
char huoer2_p[5] = {empty, white, empty, white, empty};
//10分
char sier1[4] = {empty, black, black, white};
char sier2[4] = {white, black, black, empty};
char huoyi[3] = {empty, black, empty};

char sier1_p[4] = {empty, white, white, black};
char sier2_p[4] = {black, white, white, empty};
char huoyi_p[3] = {empty, white, empty};

//1
char siyi1[3] = { white,black,empty };
char siyi2[3] = { empty,black,white };

char siyi1_p[3] = { black,white,empty };
char siyi2_p[3] = { empty,white,black };
//局势评分

int evaluate(char sequance[][15])
{
	int score = 0;
	for (int i = 0; i < 72; i++)
	{
		//100000
		score += (200000 * find(sequance[i], chenwu, 5));

		score -= (200000 * find(sequance[i], chenwu_p, 5));
		//10000
		score += (20000 * find(sequance[i], huosi1, 6));
		score += (10000 * find(sequance[i], huosi2, 7));
		score += (10000 * find(sequance[i], huosi3, 7));
		score += (10000 * find(sequance[i], huosi4, 7));

		score -= (24000 * find(sequance[i], huosi1_p, 6));
		score -= (12000 * find(sequance[i], huosi2_p, 7));
		score -= (12000 * find(sequance[i], huosi3_p, 7));
		score -= (12000 * find(sequance[i], huosi4_p, 7));
		//1000
		score += (5000 * find(sequance[i], sisi1, 6));
		score += (5000 * find(sequance[i], sisi2, 6));
		score += (5000 * find(sequance[i], sisi3, 7));
		score += (5000 * find(sequance[i], sisi4, 7));
		score += (5000 * find(sequance[i], sisi5, 7));
		score += (5000 * find(sequance[i], sisi6, 7));
		score += (5000 * find(sequance[i], sisi7, 7));
		score += (5000 * find(sequance[i], sisi8, 7));
		score += (2000 * find(sequance[i], huosan1, 5));
		score += (1000 * find(sequance[i], huosan2, 6));
		score += (1000 * find(sequance[i], huosan3, 6));
		score += (1000 * find(sequance[i], huosan4, 6));
		score += (1000 * find(sequance[i], huosan5, 6));

		score -= (6000 * find(sequance[i], sisi1_p, 6));
		score -= (6000 * find(sequance[i], sisi2_p, 6));
		score -= (6000 * find(sequance[i], sisi3_p, 7));
		score -= (6000 * find(sequance[i], sisi4_p, 7));
		score -= (6000 * find(sequance[i], sisi5_p, 7));
		score -= (6000 * find(sequance[i], sisi6_p, 7));
		score -= (6000 * find(sequance[i], sisi7_p, 7));
		score -= (6000 * find(sequance[i], sisi8_p, 7));
		score -= (2400 * find(sequance[i], huosan1_p, 5));
		score -= (1200 * find(sequance[i], huosan2_p, 6));
		score -= (1200 * find(sequance[i], huosan3_p, 6));
		score -= (1200 * find(sequance[i], huosan4_p, 6));
		score -= (1200 * find(sequance[i], huosan5_p, 6));
		//100
		score += (100 * find(sequance[i], sisan1, 5));
		score += (100 * find(sequance[i], sisan2, 5));
		score += (100 * find(sequance[i], huoer1, 4));
		score += (100 * find(sequance[i], huoer2, 5));

		score -= (120 * find(sequance[i], sisan1_p, 5));
		score -= (120 * find(sequance[i], sisan2_p, 5));
		score -= (120 * find(sequance[i], huoer1_p, 4));
		score -= (120 * find(sequance[i], huoer2_p, 5));
		//10
		score += (10 * find(sequance[i], sier1, 4));
		score += (10 * find(sequance[i], sier2, 4));
		score += (10 * find(sequance[i], huoyi, 3));

		score -= (10 * find(sequance[i], sier1_p, 4));
		score -= (10 * find(sequance[i], sier2_p, 4));
		score -= (10 * find(sequance[i], huoyi_p, 3));
		//1
		score += (1 * find(sequance[i], siyi1, 3));
		score += (1 * find(sequance[i], siyi1, 3));

		score -= (1 * find(sequance[i], siyi1_p, 3));
		score -= (1 * find(sequance[i], siyi1_p, 3));
	}
	if(computer_color==black)return score;
	else return -score;
}
