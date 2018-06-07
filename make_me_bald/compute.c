#include "const.h"

void computer_do(char chess[][15])
{
	//char neighbor[15][15];
	//int scores[15][15];
	//for (int i = 0; i < 15; i++)
	//{
	//	for (int j = 0; j < 15; j++)
	//	{
	//		neighbor[i][j] = 0;
	//		scores[i][j] = 0;
	//	}
	//}
	//generator(chess, neighbor);
	//for (int i = 0; i < 15; i++)
	//{
	//	for (int j = 0; j < 15; j++)
	//	{
	//		if (neighbor[i][j] != 0)
	//		{
	//			scores[i][j]=minimax(chess,DEPTH);
	//			//scores[i][j] = do_score(chess, i, j);
	//			//************************************************
	//		}
	//	}
	//}
	//int x = 0, y = 0, maxscore = 0;
	//for (int i = 0; i < 15; i++)
	//{
	//	for (int j = 0; j < 15; j++)
	//	{
	//		if (scores[i][j] > maxscore)
	//		{
	//			maxscore = scores[i][j];
	//			x = i;
	//			y = j;
	//		}
	//	}
	//}
	int scores_1[15][15], scores_2[15][15], scores_3[15][15], scores_temp1, scores_temp2, scores_temp3;
	char chess_temp[15][15], neighbors_1[15][15], neighbors_2[15][15], neighbors_3[15][15],x,y;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbors_1[i][j] = 0;
			neighbors_2[i][j] = 0;
			neighbors_3[i][j] = 0;
			chess_temp[i][j] = chess[i][j];
		}
	}
	generator(chess_temp, neighbors_1);
	scores_temp1 = -1000000000;
	for (int i_1 = 0; i_1 < 15; i_1++)
	{
		for (int j_1 = 0; j_1 < 15; j_1++)
		{
			//计算机下棋
			if (neighbors_1[i_1][j_1] != 0)
			{
				chess_temp[i_1][j_1] = computer_color;
				generator(chess_temp, neighbors_2);
				scores_temp2 = 1000000000;
				for (int i_2 = 0; i_2 < 15; i_2++)
				{
					for (int j_2 = 0; j_2 < 15; j_2++)
					{
						if (neighbors_1[i_2][j_2] != 0)
						{
							//玩家下棋
							chess_temp[i_2][j_2] = player_color;
							generator(chess_temp, neighbors_3);
							scores_temp3 = -1000000000;
							for (int i_3 = 0; i_3 < 15; i_3++)
							{
								for (int j_3 = 0; j_3 < 15; j_3++)
								{
									if (neighbors_1[i_3][j_3] != 0)
									{
										//计算机下棋
										chess_temp[i_3][j_3] = computer_color;
										scores_3[i_3][j_3] = scoring(chess_temp);
										scores_temp3 = scores_temp3 > scores_3[i_3][j_3] ? scores_temp3 : scores_3[i_3][j_3];
										chess_temp[i_3][j_3] = empty;
									}
								}
							}
							scores_2[i_2][j_2] = scores_temp3;
							scores_temp2 = scores_temp2 < scores_2[i_2][j_2] ? scores_temp2 : scores_2[i_2][j_2];
						}
					}
				}
				scores_1[i_1][j_1] = scores_temp2;
				if (scores_temp1 < scores_1[i_1][j_1])
				{
					scores_temp1 = scores_1[i_1][j_1];
					x = i_1;
					y = j_1;
				}
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
	char chess_temp[15][15], sequance[72][16];
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

int scoring(char chess[][15])
{
	char sequance[72][16];
	int score;
	flat(chess, sequance);
	score = evaluate(sequance);
	return score;
}