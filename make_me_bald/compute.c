#include "const.h"

void computer_do(char chess[][15])
{
	struct point p;
	p = maxmin(chess, DEPTH);
	chess[p.x][p.y] = computer_color;
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
				if (temp_x < 0 || temp_x>=15) continue;
				for (int j = -NEIGHBOR_DEPTH; j <= NEIGHBOR_DEPTH; j++)
				{
					temp_y = y + j;
					if (temp_y < 0 || temp_y>=15) continue;
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
		for (int j = 0; j <= i; j++)
		{
			sequance[i + 30][j] = chess[j][i - j];
		}
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = 14; j >= i; j--)
		{
			sequance[i + 41][j] = chess[i + 14 - j][j];
		}
	}
	//"\"这样的序列
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j <= 14 - i; j++)
		{
			sequance[i + 51][j] = chess[i + j][j];
		}
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = i-1; j <= 14 - i; j++)
		{
			sequance[i + 62][j] = chess[j][i + j];
		}
	}
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

int do_score(char chess[][15], int x, int y)
{
	char sequance[72][16];
	int score;
	chess[x][y] = computer_color;
	flat(chess, sequance);
	chess[x][y] = empty;
	score = evaluate(sequance);
	return score;
}

int scoring(char chess[][15])
{
	char sequance[72][16];
	int score;
	flat(chess, sequance);
	score = evaluate(sequance);
	return score;
}