#include "const.h"
#include <conio.h>
#include <stdlib.h>

//函数前方加上 ab_ 以示与极大极小值搜索的区别

int ab_min(char chess[][15], int depth, int alpha, int beta)
{
	int temp, best = MAX; 
	neighbor * neighbor_p, *temp_p;
	if (depth <= 0 || whos_winner(chess) != empty)
	{
		best = scoring(chess);
		return best;
	}
	neighbor_p=generator(chess);
	while (neighbor_p != NULL)
	{
		chess[neighbor_p->p.x][neighbor_p->p.y] = player_color;
		temp = ab_max(chess, depth - 1, best < alpha ? best : alpha, beta);
		chess[neighbor_p->p.x][neighbor_p->p.y] = empty;
		temp_p = neighbor_p;
		neighbor_p = neighbor_p->next;
		free(temp_p);
		if (temp < best)
		{
			best = temp;
		}
		if (temp <= beta) return temp;
	}
	return best;
}

int ab_max(char chess[][15], int depth, int alpha, int beta)
{
	int temp, best = MIN;
	neighbor * neighbor_p, *temp_p;
	if (depth <= 0 || whos_winner(chess) != empty)
	{
		best = scoring(chess);
		return best;
	}
	neighbor_p=generator(chess);
	while (neighbor_p != NULL)
	{
		chess[neighbor_p->p.x][neighbor_p->p.y] = player_color;
		temp = ab_max(chess, depth - 1, alpha, best > beta ? best : beta);
		chess[neighbor_p->p.x][neighbor_p->p.y] = empty;
		temp_p = neighbor_p;
		neighbor_p = neighbor_p->next;
		free(temp_p);
		if (temp > best)
		{
			best = temp;
		}
		if (temp >= alpha) return temp;
	}
	return best;
}