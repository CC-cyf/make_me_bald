#include "const.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("mode con cols=50 lines=22");
	char x, y, winner = empty;
	int chess_num = 0;
	//extern player_color, computer_color;
	char chess[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			chess[i][j] = empty;
		}
	}
reinput_color:
	draw(chess);
	printf("请输入您所控制的棋子颜色:\n1.白色（后手）\n2.黑色（先手）");
	scanf("%d", &player_color);
	fflush(stdin);
	player_color++;
	if (player_color != white && player_color != black)
	{
		printf("输入错误!\n");
		getchar();
		goto reinput_color;
	}
	computer_color = 5 - player_color;
	//如果机器先手，下第一步
	if (chess_num == 0 && player_color == white)
	{
		chess[7][7] = computer_color;
		chess_num++;
	}
	//*************************************************
	while (winner == empty)
	{
	reinput_position:
		draw(chess);
		printf("请输入行号（0-14）：");
		scanf("%d", &x);
		fflush(stdin);
		getchar();
		if (x > 14 || x < 0)
		{
			printf("错误行号！！！");
			getchar();
			goto reinput_position;
		}
		printf("\n请输入列号（a-o）：");
		scanf("%c", &y);
		fflush(stdin);
		getchar();
		y = y - 'a';
		if (y > 14 || y < 0)
		{
			printf("错误列号！！！");
			getchar();
			goto reinput_position;
		}
		if (chess[x][y] == empty)
		{
			chess[x][y] = player_color;
			chess_num++;
		}
		else
		{
			printf("该位置已经被占用！！！");
			getchar();
			goto reinput_position;
		}
		draw(chess);
		computer_do(chess);
		chess_num++;
		winner = whos_winner(chess);
	}
	//*********************************************
	if (winner == player_color)
	{
		system("cls");
		printf("");
	}
}

void draw(char chess[][15])
{
	system("cls");
	printf("*代表白子，%c 代表黑子\n", 1);
	printf("\t");
	for (int i = 0; i < 15; i++)
	{
		printf("%c ", 'a' + i);
	}
	printf("\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d", i);
		printf("\t");
		for (int j = 0; j < 15; j++)
		{
			if (chess[i][j] == black)
			{
				printf("%c ", 1);
			}
			else if (chess[i][j] == white)
			{
				printf("* ");
			}
			else
			{
				printf("+ ");
			}
		}
		printf("\n");
	}
}

char whos_winner(char chess[][15])
{
	char sequance[72][16];
	char player_win[5] = { player_color,player_color,player_color,player_color,player_color };
	char computer_win[5] = { computer_color,computer_color,computer_color,computer_color,computer_color };
	flat(chess, sequance);
	for (int i = 0; i < 72; i++)
	{
		if (find(sequance[i], player_win, 5) != 0) return player_color;
		if (find(sequance[i], computer_win, 5) != 0) return computer_color;
	}
	return empty;
}