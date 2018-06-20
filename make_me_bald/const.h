#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define false 0
#define true 1
#define DEPTH 2
#define KILL_DEPTH 3
#define NEIGHBOR_DEPTH 2
#define MAX 1000000000
#define MIN -1000000000
enum chesses { empty = 1, white, black };
typedef struct point { int x; int y; }point;
typedef struct neighbor { struct point p; struct neighbor * next; }neighbor;
int player_color, computer_color;
char chess[15][15];

//main.c
void draw(char chess[][15]);
char whos_winner(char chess[][15]);

//compute.c
void computer_do(char chess[][15]);
neighbor * generator(char chess[][15]);
void flat(char chess[][15], char sequance[][15]);
char find(char place[15], char goal[], char length);
int do_score(char chess[][15], int x, int y);
int scoring(char chess[][15]);

//evaluate.c
int evaluate(char sequance[][15]);

//minimax.c
int mini(char chess[][15], int depth);
int maxi(char chess[][15], int depth);
point maxmin(char chess[][15], int depth);

//alpha_beta.c
int ab_min(char chess[][15], int depth, int alpha, int beta);
int ab_max(char chess[][15], int depth, int alpha, int beta);