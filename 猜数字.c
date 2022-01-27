#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game()
{
	int x = 0;
	x = rand() % 100 + 1;
	int count = 1;
	printf("%d\n", x);
	printf("你只有5次机会\n");
	printf("请输入你想猜的数字:");
	while (1)
	{
		
		int y = 0;
		scanf("%d", &y);
		if (x > y)
		{
			if (count < 5)
			{
				printf("太小了\n");
				printf("请继续猜:");
				count++;
			}
			else
			{
				printf("游戏结束了，你个fw\n");
				break;
			}
		}
		else if (x < y)
		{
			if (count < 5) 
			{
				printf("太大了\n");
				printf("请继续猜:");
				count++;
			}
			else
			{
				printf("游戏结束了，你个fw\n");
				break;
			}
		}

		if (x == y)
		{
			printf("恭喜你这B，猜对了\n\a\a\a");
			break;
		}


	}
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("欢迎来到猜数字游戏\n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("请输入你的选项:");
	int a = 0;
	eg1:scanf("%d", &a);
	switch (a)
	{
	case 1: game(); break;
	case 2:printf("很遗憾,你选择了退出游戏\n"); break;
	default: printf("选择非法，请重新选择:"); goto eg1; break;
	}

	return 0;
}
