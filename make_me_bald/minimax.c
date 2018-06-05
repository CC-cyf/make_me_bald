#include "const.h"

int minimax(char chess[][15], int x, int y, char depth)
{
	int scores, scores_temp;
	if (depth == 1)
	{
		scores = do_score(chess, x, y);
		return scores;
	}
	char chess_temp[15][15], neighbors[15][15];
	generator(chess, neighbors);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			chess_temp[i][j] = chess[i][j];
		}
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				if (depth % 2)
				{
					chess[i][j] = computer_color;
				}
				else
				{
					chess[i][j] = player_color;
				}
				scores_temp = minimax(chess_temp, depth - 1, i, j);
				if (depth % 2)
				{
					scores = scores > scores_temp ? scores : scores_temp;
				}
				else
				{
					scores = scores < scores_temp ? scores : scores_temp;
				}
			}
		}
	}
	return scores;
}