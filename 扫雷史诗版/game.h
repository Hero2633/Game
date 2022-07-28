#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#define MINE_COUNT 10//
#define ROW 9//
#define COL 9//更改这三部变换难度；
#define ROWS ROW+2
#define COLS COL+2
enum CHOOSE
{
	EXIT,
	PLAY,
};
extern int flag;
extern int setp;
void init_board(char a[][COLS], int r, int c, char set);//初始化棋盘
void display_board(char a[][COLS], int r, int c);//打印棋盘
void set_mine(char mine[][COLS], int r, int c,int count);//布置雷
void find_mine(char show[][COLS], char mine[][COLS], int r, int c);//排查雷；
int get_mine(char show[][COLS], char mine[][COLS], int r, int c);//得到雷的数量
bool is_mine(char mine[][COLS], int x, int y);//判断下x，y是否为雷；
bool is_find(char show[][COLS], int x, int y);//判断是否被排查过
void surprise(char mine[][COLS], char show[][COLS], int r, int c, int x, int y);//展开一片