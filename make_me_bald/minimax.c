#include "const.h"
#include <conio.h>
#include <stdlib.h>

point maxmin(char chess[][15], int depth)
{
	struct point p;
	int best = MIN, temp,score[15][15], alpha = MAX;
	neighbor *neighbor_p, *temp_p;
	neighbor_p=generator(chess);
	while (neighbor_p != NULL)
	{
		chess[neighbor_p->p.x][neighbor_p->p.y] = computer_color;
		temp = ab_min(chess, depth - 1, alpha, best > MIN ? best : MIN);
		score[neighbor_p->p.x][neighbor_p->p.y] = temp;
		if (temp == best)
		{
			p.x = neighbor_p->p.x;
			p.y = neighbor_p->p.y;
		}
		if (temp > best)
		{
			best = temp;
			p.x = neighbor_p->p.x;
			p.y = neighbor_p->p.y;
		}
		chess[neighbor_p->p.x][neighbor_p->p.y] = empty;
		temp_p = neighbor_p;
		neighbor_p = neighbor_p->next;
		free(temp_p);
	}
	return p;
}

int mini(char chess[][15], int depth)
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
	generator(chess);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				chess[i][j] = player_color;
				temp = maxi(chess, depth - 1);
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

int maxi(char chess[][15], int depth)
{
	int best = MIN, temp;
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
	generator(chess);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (neighbors[i][j] != 0)
			{
				chess[i][j] = computer_color;
				temp = mini(chess, depth - 1);
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