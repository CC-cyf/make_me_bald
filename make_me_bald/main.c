#include "const.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("mode con cols=50 lines=22");
	char x, y, winner=empty;
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
		winner == whos_winner(chess);
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
	}
//*********************************************
}

void draw(char chess[][15])
{
	system("cls");
	printf("*代表白子，%c 代表黑子\n",1);
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
				printf("%c ",1);
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

char whos_winner(char chess[][15])  //*************************** 
{
	char white_num, black_num;
	//横向查找
	for (int i = 0; i < 15; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 0; j < 15; j++)
		{
			if (chess[i][j] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[i][j] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	//纵向查找
	for (int i = 0; i < 15; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 0; j < 15; j++)
		{
			if (chess[j][i] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[j][i] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	//"/"这样查找
	for (int i = 4; i < 15; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 0; j <= i; j++)
		{
			if (chess[j][i - j] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[j][i - j] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	for (int i = 1; i < 11; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 14; j >= i; j--)
		{
			if (chess[i + 14 - j][j] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[i + 14 - j][j] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	//"\"这样查找
	for (int i = 0; i < 11; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 0; j < 15 - i; j++)
		{
			if (chess[i + j][j] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[i + j][j] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	for (int i = 1; i < 11; i++)
	{
		white_num = 0;
		black_num = 0;
		for (int j = 0; j < 15 - i; j++)
		{
			if (chess[j][i + j] == white)
			{
				white_num++;
				black_num = 0;
			}
			else if (chess[j][i + j] == black)
			{
				black_num++;
				white_num = 0;
			}
			else
			{
				white_num = 0;
				black_num = 0;
			}
			if (black_num == 5)return black;
			if (white_num == 5)return white;
		}
	}
	return empty;
}