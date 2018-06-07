#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define false 0
#define true 1
#define DEPTH 3
#define KILL_DEPTH 3
#define NEIGHBOR_DEPTH 2
enum chesses { empty = 1, white, black };
struct point { int x; int y };
int player_color, computer_color;

//main.c
void draw(char chess[][15]);
char whos_winner(char chess[][15]);

//compute.c
void computer_do(char chess[][15]);
void generator(char chess[][15], char neighbors[][15]);
void flat(char chess[][15], char sequance[][16]);
char find(char place[16], char goal[], char length);
int do_score(char chess[][15], int x, int y);
int scoring(char chess[][15]);

//evaluate.c
int evaluate(char sequance[][16]);

//alpha_beta.c
int alpha_beta(int score, int alpha, int beta);

//minimax.c
int min(char chess[][15], int depth);
int max(char chess[][15], int depth);
int minimax(char chess[][15], char position[]);