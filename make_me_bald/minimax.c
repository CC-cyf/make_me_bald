#include "const.h"

struct point maxmin(char chess[][15], int depth)
{
	struct point p;
	int best = MIN, temp, scores[15][15];
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
	int best = MAX, temp;
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
	int best = MIN, temp;
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