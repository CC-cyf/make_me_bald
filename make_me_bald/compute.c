#include "const.h"

void computer_do(char chess[][15])
{
	char neighbor[15][15];
	int scores[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbor[i][j] = empty;
			scores[i][j] = 0;
		}
	}
	generator(chess, neighbor);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbor[i][j] != empty)
			{
				scores[i][j]=score(chess, i, j);
				//************************************************
			}
		}
	}
	int x=0, y=0, maxscore=0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (scores[i][j] > maxscore)
			{
				maxscore = scores[i][j];
				x = i;
				y = j;
			}
		}
	}
	chess[x][y] = computer_color;
}

//生成待计算的位置图
void generator(char chess[][15], char neighbors[][15])
{
	int x, y, temp_x, temp_y;
	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 15; y++)
		{
			if (chess[x][y] != empty) continue;
			for (int i = -NEIGHBOR_DEPTH; i <= NEIGHBOR_DEPTH; i++)
			{
				temp_x = x + i;
				if (temp_x < 0 || temp_x>15) continue;
				for (int j = -NEIGHBOR_DEPTH; j <= NEIGHBOR_DEPTH; j++)
				{
					temp_y = y + j;
					if (temp_y < 0 || temp_y>15) continue;
					if (chess[temp_x][temp_y] != empty)
					{
						neighbors[x][y]++;
					}
				}
			}
		}
	}
}

//将棋盘序列化，以便于评估
void flat(char chess[][15], char sequance[][16])
{
	//横向序列
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sequance[i][j] = chess[i][j];
		}
	}
	//纵向序列
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			sequance[i + 15][j] = chess[j][i];
		}
	}
	//"/"这样的序列
	for (int i = 4; i < 15; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sequance[i + 30][j] = chess[j][i - j];
		}
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = 14; j > i; j--)
		{
			sequance[i + 41][j] = chess[i + 14 - j][j];
		}
	}
	//"\"这样的序列
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 14 - i; j++)
		{
			sequance[i + 51][j] = chess[i + j][j];
		}
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = 0; j < 14 - i; j++)
		{
			sequance[i + 62][j] = chess[j][i + j];
		}
	}
}

//局势评分
int evaluate(char sequance[][16])
{
	int score = 0;
	//100000分
	char chenwu[5] = { computer_color,computer_color,computer_color,computer_color,computer_color };
	//10000分
	char huosi1[6] = { empty,computer_color,computer_color,computer_color,computer_color,empty };
	char huosi2[5] = { computer_color,empty,computer_color,computer_color,computer_color };
	char huosi3[5] = { computer_color,computer_color,empty,computer_color,computer_color };
	char huosi4[5] = { computer_color,computer_color,computer_color,empty,computer_color };
	//1000分
	char sisi1[6] = { empty,computer_color,computer_color,computer_color,computer_color,player_color };
	char sisi2[6] = { player_color,computer_color,computer_color,computer_color,computer_color,empty };
	char huosan[5] = { empty,computer_color,computer_color,computer_color,empty };
	//100分
	char sisan1[5] = { empty,computer_color,computer_color,computer_color,player_color };
	char sisan2[5] = { player_color,computer_color,computer_color,computer_color,empty };
	char huoer[4] = { empty,computer_color,computer_color,empty };
	//10分
	char sier1[4] = { empty,computer_color,computer_color,player_color };
	char sier2[4] = { player_color,computer_color,computer_color,empty };
	char huoyi[3] = { empty,computer_color,empty };
	//*********************************************************************************
	for (int i = 0; i <= 72; i++)
	{
		//100000
		score += (100000 * find(sequance[i], chenwu, 5));
		//10000
		score += (10000 * find(sequance[i], huosi1, 6));
		score += (10000 * find(sequance[i], huosi2, 5));
		score += (10000 * find(sequance[i], huosi3, 5));
		score += (10000 * find(sequance[i], huosi4, 5));
		//1000
		score += (1000 * find(sequance[i], sisi1, 6));
		score += (1000 * find(sequance[i], sisi2, 6));
		score += (1000 * find(sequance[i], huosan, 5));
		//100
		score += (100 * find(sequance[i], sisan1, 5));
		score += (100 * find(sequance[i], sisan2, 5));
		score += (100 * find(sequance[i], huoer, 4));
		//10
		score += (10 * find(sequance[i], sier1, 4));
		score += (10 * find(sequance[i], sier2, 4));
		score += (10 * find(sequance[i], huoyi, 3));
	}
	return score;
}

//在序列中查找指定序列，并返回出现次数
char find(char place[16], char goal[], char length)
{
	char show_up_times = 0;
	_Bool temp;
	for (int i = 0; i < 16 - length; i++)
	{
		temp = 1;
		for (int j = 0; j < length; j++)
		{
			if (place[i + j] != goal[j])
			{
				temp = 0;
			}
		}
		if (temp == 1)
		{
			show_up_times++;
		}
	}
	return show_up_times;
}

int score(char chess[][15], int x, int y)
{
	char chess_temp[15][15],sequance[72][16];
	int score;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			chess_temp[i][j] = chess[i][j];
		}
	}
	chess_temp[x][y] = computer_color;
	flat(chess_temp, sequance);
	score = evaluate(sequance);
	return score;
}