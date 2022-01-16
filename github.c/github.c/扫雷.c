#define _CRT_SECURE_NO_WARNINGS
#include"game2.h"
void mean()
{
	printf("    扫雷  \n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("请选择你的选项:");
}
void game()
{
	char arr1[Hs][Ls] = { 0 };//此数组用于布置雷；
	char arr2[Hs][Ls] = { 0 };//此数组用于排查雷，最终呈现的也只有该数组；
	cssz(arr1,Hs,Ls,' ');//地雷；@
	cssz(arr2,Hs,Ls,'*');//无雷；‘ ’
	/*dyqp(arr1,H,L);*///打印初始化过的棋盘；
	dyqp(arr2,H,L);
	bzdl(arr1, H, L);//开始随机埋雷；
	/*dyqp(arr1, H, L);*/
	while (1)
	{
		int x= 0,y=0;
		printf("请输入你想排查的坐标:");
		eg2:scanf("%d %d", &x,&y);
		int z = pcdl(arr1, x, y);
		if (x >= 1 && x < 10 && y >= 1 && y < 10)
		{
			if (arr2[x][y] == '*')
			{
				if (z == -1)
				{
					printf("很遗憾您踩到地雷了,哈哈,游戏结束\n\a\a\a");
					printf("答案>>>>>\n");
					dyqp(arr1, H, L);
					break;
				}
				else
				{
					int a = pcdl(arr1, x, y);
					char f = 0;
					f = '0' + a;//将数字转换为字符，例如‘6’=‘0’+6；
					arr2[x][y] = f;//（x，y）周围地雷颗数；
					/*dyqp(arr1, H, L);*/
					dyqp(arr2, H, L);
				}
			}
			else
			{
				printf("此位置已被占，请重新输入:");
				goto eg2;
			}
		}
		else
		{
			printf("你输入的坐标不合法，请重新输入:");
			goto eg2;


		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int a = 0;
	mean();
	eg1:scanf("%d", &a);
	switch (a)
	{
	case 1:
	game(); 
	break;
	case 2:
		printf("退出\n"); break;
	default:printf("输入选项未拥有,请重新输入:");
		goto eg1;
		break;
	}
	return 0;
}