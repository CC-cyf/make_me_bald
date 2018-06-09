#include "const.h"

//函数前方加上 ab_ 以示与极大极小值搜索的区别

int ab_min(char chess[][15], int depth, int alpha, int beta)
{
	int temp, best = MAX;
	if (depth <= 0 || whos_winner(chess) != empty)
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
				chess[i][j] = player_color;
				temp = ab_max(chess, depth - 1, best < alpha ? best : alpha, beta);
				chess[i][j] = empty;
				if (temp < best)
				{
					best = temp;
				}
				if (temp < beta) break;
			}
		}
	}
	return best;
}

int ab_max(char chess[][15], int depth, int alpha, int beta)
{
	int temp, best = MIN;
	if (depth <= 0 || whos_winner(chess) != empty)
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
			if (neighbors != 0)
			{
				chess[i][j] = computer_color;
				temp = ab_min(chess, depth - 1, alpha, best > beta ? best : beta);
				chess[i][j] = empty;
				if (temp > best)
				{
					best = temp;
				}
				if (temp > alpha)break;
			}
		}
	}
	return best;
}