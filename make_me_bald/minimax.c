#include "const.h"

struct point maxmin(char chess[][15],int depth)
{
	struct point p;
	int best = -1000000000, temp;
	char neighbors[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbors[i][j] = 0;
		}
	}
	generator(chess, neighbors);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				chess[i][j] = computer_color;
				temp = min(chess, depth - 1);
				if (temp == best)
				{
					p.x = i;
					p.y = j;
				}
				if (temp > best)
				{
					best = temp;
					p.x = i;
					p.y = j;
				}
				chess[i][j] = empty;
			}
		}
	}
	return p;
}

int min(char chess[][15], int depth)
{
	int best = 1000000000, temp;
	if (depth <= 0 || whos_winner(chess) != empty)
	{
		best = scoring(chess);
		return best;
	}
	char neighbors[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbors[i][j] = 0;
		}
	}
	generator(chess, neighbors);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				chess[i][j] = player_color;
				temp = max(chess, depth - 1);
				chess[i][j] = empty;
				if (temp < best)
				{
					best = temp;
				}
			}
		}
	}
	return best;
}

int max(char chess[][15], int depth)
{
	int best = -1000000000, temp;
	if (depth <= 0 || whos_winner(chess))
	{
		temp = scoring(chess);
		return temp;
	}
	char neighbors[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbors[i][j] = 0;
		}
	}
	generator(chess, neighbors);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				chess[i][j] = computer_color;
				temp = min(chess, depth - 1);
				chess[i][j] = empty;
				if (temp > best)
				{
					best = temp;
				}
			}
		}
	}
	return best;
}

/*int minimax(char chess[][15], char depth)
{
	int scores[15][15], scores_temp, scores_out;
	char chess_temp[15][15], neighbors[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			neighbors[i][j] = 0;
			chess_temp[i][j] = chess[i][j];
		}
	}
	generator(chess_temp, neighbors);
	if (depth == 1)
	{
		scores_out = -1000000000;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (neighbors[i][j] != 0)
				{
					chess_temp[i][j] = computer_color;
					scores[i][j] = do_score(chess_temp, i, j);
					scores_out = scores_out > scores[i][j] ? scores_out : scores[i][j];
					chess_temp[i][j] = empty;
				}
			}
		}
		return scores_out;
	}
	if (depth % 2)
	{
		scores_out = -1000000000;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (neighbors[i][j] != 0)
				{
					chess_temp[i][j] = computer_color;
					scores[i][j] = minimax(chess_temp, depth - 1);
					scores_out = scores_out > scores[i][j] ? scores_out : scores[i][j];
					chess_temp[i][j] = empty;
				}
			}
		}
	}
	else
	{
		scores_out = 1000000000;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (neighbors[i][j] != 0)
				{
					chess_temp[i][j] = computer_color;
					scores[i][j] = minimax(chess_temp, depth - 1);
					scores_out = scores_out < scores[i][j] ? scores_out : scores[i][j];
					chess_temp[i][j] = empty;
				}
			}
		}
	}
	return scores_out;
}

int minimax(char chess[][15],char position[])
{
	int scores_1[15][15], scores_2[15][15], scores_3[15][15], scores_temp1, scores_temp2, scores_temp3;
	char chess_temp[15][15], neighbors_1[15][15], neighbors_2[15][15], neighbors_3[15][15];
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
							for (int i_3=0; i_3 < 15; i_3++)
							{
								for (int j_3=0; j_3 < 15; j_3++)
								{
									if (neighbors_1[i_3][j_3] != 0)
									{
										//计算机下棋
										chess_temp[i_3][j_3] = computer_color;
										scores_3[i_3][j_3]=scoring(chess_temp);
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
					position[0] = i_1;
					position[2] = j_1;
				}
			}
		}
	}
	return 0;
}*/