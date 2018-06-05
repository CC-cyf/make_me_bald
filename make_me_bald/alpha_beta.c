#include "const.h"

/*int alpha_beta(char chess[][15], int *scores, int *alpha, int *beta, char depth, char x, char y)
{
	if (depth == 1)
	{
		*scores = do_score(chess, x, y);
		*alpha = *scores;
		return 0;
	}
	else
	{
		signed int scores_temp, scores_in;
		if (depth % 2)
		{
			scores_temp = -2147483640;         //负无穷
			scores_in = -2147483640;         //负无穷
		}
		else
		{
			scores_temp = 2147483640;          //正无穷
			scores_in = 2147483640;          //正无穷
		}
		char chess_temp[15][15], neighbor[15][15];
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				chess_temp[i][j] = chess[i][j];
			}
		}
		generator(chess_temp, neighbor);
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (neighbor[i][j] != 0)
				{
					alpha_beta(chess_temp, &scores_in, alpha, beta, depth - 1, i, j);
					if (depth % 2)
					{
						if (scores_temp > scores_in)
						{
							scores_temp = scores_in;
							alpha = scores_in;
						}
					}
					else
					{
						if (scores_temp < scores_in)
						{
							scores_temp = scores_in;
							beta = scores_in;
						}
					}
				}
			}
		}
	}
}*/