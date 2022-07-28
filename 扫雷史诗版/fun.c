#define  _CRT_SECURE_NO_WARNINGS 0
#include "game.h"
#pragma warning (disable:6031)
void init_board(char a[][COLS], int r, int c, char set)
{
	int i = 1;
	int j = 1;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			a[i][j] = set;
		}
	}
}
void display_board(char a[][COLS], int r, int c)
{
	int i = 1;
	int j = 1;
	printf(" ");
	for (j = 0; j <= c; j++)
	{
		if(j<10)
		printf("%d ",j);
		else
		{
			printf("%c ",'A'+j-10);
		}
	}
	putchar('\n');
	for (j = 0; j <= c; j++)
	{
		printf("--");
	}
	putchar('\n');
	for (i = 1; i <= r; i++)
	{
		if (i < 10)
			printf("%d| ", i);
		else
		{
			printf("%c| ", 'A' + i - 10);
		}
		for (j = 1; j <= c; j++)
		{
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char mine[][COLS], int r, int c,int count)
{
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % r + 1;
	    y = rand() % c + 1;
		if (mine[x][y] == ' ')
		{
			mine[x][y] = '#';
			count--;
		}
	}
}
void find_mine(char show[][COLS],char mine [][COLS], int r, int c)//看看能不能在优化；
{
	int x = 0;
	int y = 0;
	char ch = 0;
	while (1)
	{
		printf("请输入你要排查的位置,并选择是否对该点进行标识(Y\\其它默认不标记)>");//对同一个点多次标记会取消标记；
		scanf("%d %d %c", &x, &y,&ch);
		if (x >= 1 && x <= r && y >= 1 && y <= c)//坐标合法
		{ 
			if (!is_find(show, x, y))//未被排查过
			{
				if (show[x][y] == 'M' && 'Y' == ch)
				{		show[x][y] = '*';
				printf("取消标记成功\n");
				system("cls");
				display_board(show,r,c);
				break;
			    }
				if ('Y' == ch)//判断一下是否需要标记；
				{
					show[x][y] = 'M';
					printf("标记成功\n");
					system("cls");
					display_board(show, r, c);
					break;
				}
				else
				{
					if ('Y' == ch)
					{
						printf("请不要对已经排查过的点进行标记\a\a\a\n");
						printf("请重新输入\n");
						break;
					}
					else
					{
						if (is_mine(mine, x, y))
						{
							printf("你被雷炸死了\n\a\a\a");
							show[x][y] = '@';
							flag = 0;
							system("cls");
							display_board(mine, r, c);
							break;
						}
						else//不是雷
						{
							surprise(mine, show, r, c, x, y);
							system("cls");
							display_board(show, r, c);
							break;
						}
					}
				}
			}
			else
			{
				printf("坐标已排查过,请重新输入:>\n");
			}

		}
		else
			printf("坐标非法,请重新输入\n");
	}
}
int get_mine(char show[][COLS], char mine[][COLS], int x, int y)
{
	int count = 0;
	if (mine[x - 1][y - 1] == '#')
		count++;
	if (mine[x - 1][y] == '#')
		count++;
	if (mine[x - 1][y + 1] == '#')
		count++;
	if (mine[x ][y - 1] == '#')
		count++;
	if (mine[x][y + 1] == '#')
		count++;
	if (mine[x +1][y - 1] == '#')
		count++;
	if (mine[x + 1][y] == '#')
		count++;
	if (mine[x + 1][y + 1] == '#')
		count++;
	return count;
}
bool is_mine(char mine[][COLS], int x, int y)
{
	if (mine[x][y] == ' ')
		return false;
	return true;
}
bool is_find(char show[][COLS], int x, int y)
{
	if (show[x][y] == '*'|| show[x][y] == 'M')
		return false;
	return true;
}
void surprise(char mine[][COLS], char show[][COLS], int r, int c, int x, int y)
{
	if (!(x >= 1 && x <= r && y >= 1 && y <= c))//防止越界；
		return;
	if (is_mine(mine, x, y) ||is_find(show, x, y))//能展开的条件：1、没被排查过；2、排查位置不是雷
		return;
	setp--;
	int count = get_mine(show, mine, x, y);//3、排查位置周围没有雷；
	show[x][y] = count + '0';
	if (count == 0)
	{
		surprise(mine, show, r, c, x - 1, y - 1);
		surprise(mine, show, r, c, x - 1, y);
		surprise(mine, show, r, c, x - 1, y + 1);
		surprise(mine, show, r, c, x, y - 1);
		surprise(mine, show, r, c, x, y + 1);
		surprise(mine, show, r, c, x + 1, y - 1);
		surprise(mine, show, r, c, x + 1, y);
		surprise(mine, show, r, c, x + 1, y + 1);
	}
}