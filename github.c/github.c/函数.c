#define _CRT_SECURE_NO_WARNINGS
#include"game2.h"
void cssz(char arr[][Ls], int h, int l, char set)
{
	for (int i = 0; i < h; i++)
	{

		for (int j = 0; j < l; j++)
		{
			arr[i][j] = set;
		}
	}
}
void dyqp(char arr[][Ls],int h,int l)
{

	for (int a = 0; a <=h; a++)
	{
		printf(" %d", a);
	}
	printf("\n");
	printf("  ------------------\n");
	for (int i = 1; i <= h; i++)
	{
		printf("%d ", i);
		printf("|");
		for (int j = 1; j <=l; j++)
		{
			printf( "%c ", arr[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
}
void bzdl(char arr[][Ls], int h, int l)//地雷已经埋好;
{
	int x = 0;
	int y = 0;
	for (int a = 10; a > 0;)
	{
		x = rand() % h + 1;
		y = rand() % l + 1;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '@';
			a--;
		}
	}
}int pcdl(char arr[][Ls], int X, int Y)//排查地雷，1，有雷返回-1；2，无雷返回count；
{
	int count = 0;
	if (arr[X][Y] == '@')
	{
		return -1;
	}
	else
	{
		if (arr[X - 1][Y - 1] == '@')
			count++;
		if (arr[X - 1][Y] == '@')
			count++;
		if (arr[X - 1][Y + 1] == '@')
			count++;
		if (arr[X][Y - 1] == '@')
			count++;
		if (arr[X][Y + 1] == '@')
			count++;
		if (arr[X + 1][Y - 1] == '@')
			count++;
		if (arr[X + 1][Y] == '@')
			count++;
		if (arr[X + 1][Y + 1] == '@')
			count++;


		return count;
	}


}










