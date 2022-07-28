#define  _CRT_SECURE_NO_WARNINGS 0
#include"game.h"
#pragma warning (disable:6031)
//1、雷盘，展示盘
//2、初始化雷盘和展示盘//空格表示没雷#表示雷；*初始化展示盘
//3、打印一下棋盘；
//4、布置雷；
//5、排查雷；(注意触发惊喜)
int setp = ROW * COL - MINE_COUNT;//记录排雷最多步数；
int flag = 1;
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init_board(mine,ROW,COL,' ');//初始化
	init_board(show, ROW, COL, '*');//初始化
	set_mine(mine, ROW, COL, MINE_COUNT);//布置雷
	//display_board(mine, ROW, COL);//开透视
	display_board(show, ROW, COL);//展示棋盘（给玩家看）；
	while (setp&&flag)
	{
		find_mine(show, mine, ROW, COL);
	}
	if (setp == 0)
	{
		system("cls");
		printf("挑战成功\n");
	}
	else if(!flag)
	{
		system("cls");
		printf("挑战失败\n");
	}
	display_board(show, ROW, COL);//展示棋盘（给玩家看）；
	for (int j = 0; j <= COL; j++)
	{
		printf("--");
	}
	putchar('\n');
	display_board(mine,ROW,COL);
}

void menu()
{
	printf("**********  扫雷小游戏  *********\n");
	printf("********      1. play    ********\n");
	printf("********      0. exit    ********\n");
	printf("*********************************\n");
	printf("游戏介绍\n");
	printf("1、两次对同一个点标记，可取消标记。\n");
	printf("2、最后一次输入位置若是地雷，则该位置将会被标为@以此警示。\n");
	printf("3、若在坐标后面输入Y则表示对该点进行标记，其它默认不标记。\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			system("cls");
			game(); break;
		case EXIT:
			system("cls"); printf("退出游戏\n"); break;
		default:
			system("cls"); printf("输入有误，重新输入:>\n"); break;
		}
	} while (input);
	return 0;
}