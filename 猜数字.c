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
	printf("��ֻ��5�λ���\n");
	printf("����������µ�����:");
	while (1)
	{
		
		int y = 0;
		scanf("%d", &y);
		if (x > y)
		{
			if (count < 5)
			{
				printf("̫С��\n");
				printf("�������:");
				count++;
			}
			else
			{
				printf("��Ϸ�����ˣ����fw\n");
				break;
			}
		}
		else if (x < y)
		{
			if (count < 5) 
			{
				printf("̫����\n");
				printf("�������:");
				count++;
			}
			else
			{
				printf("��Ϸ�����ˣ����fw\n");
				break;
			}
		}

		if (x == y)
		{
			printf("��ϲ����B���¶���\n\a\a\a");
			break;
		}


	}
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("��ӭ������������Ϸ\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("���������ѡ��:");
	int a = 0;
	eg1:scanf("%d", &a);
	switch (a)
	{
	case 1: game(); break;
	case 2:printf("���ź�,��ѡ�����˳���Ϸ\n"); break;
	default: printf("ѡ��Ƿ���������ѡ��:"); goto eg1; break;
	}

	return 0;
}
