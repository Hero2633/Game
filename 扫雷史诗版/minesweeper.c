#define  _CRT_SECURE_NO_WARNINGS 0
#include"game.h"
#pragma warning (disable:6031)
//1�����̣�չʾ��
//2����ʼ�����̺�չʾ��//�ո��ʾû��#��ʾ�ף�*��ʼ��չʾ��
//3����ӡһ�����̣�
//4�������ף�
//5���Ų��ף�(ע�ⴥ����ϲ)
int setp = ROW * COL - MINE_COUNT;//��¼������ಽ����
int flag = 1;
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init_board(mine,ROW,COL,' ');//��ʼ��
	init_board(show, ROW, COL, '*');//��ʼ��
	set_mine(mine, ROW, COL, MINE_COUNT);//������
	//display_board(mine, ROW, COL);//��͸��
	display_board(show, ROW, COL);//չʾ���̣�����ҿ�����
	while (setp&&flag)
	{
		find_mine(show, mine, ROW, COL);
	}
	if (setp == 0)
	{
		system("cls");
		printf("��ս�ɹ�\n");
	}
	else if(!flag)
	{
		system("cls");
		printf("��սʧ��\n");
	}
	display_board(show, ROW, COL);//չʾ���̣�����ҿ�����
	for (int j = 0; j <= COL; j++)
	{
		printf("--");
	}
	putchar('\n');
	display_board(mine,ROW,COL);
}

void menu()
{
	printf("**********  ɨ��С��Ϸ  *********\n");
	printf("********      1. play    ********\n");
	printf("********      0. exit    ********\n");
	printf("*********************************\n");
	printf("��Ϸ����\n");
	printf("1�����ζ�ͬһ�����ǣ���ȡ����ǡ�\n");
	printf("2�����һ������λ�����ǵ��ף����λ�ý��ᱻ��Ϊ@�Դ˾�ʾ��\n");
	printf("3�����������������Y���ʾ�Ըõ���б�ǣ�����Ĭ�ϲ���ǡ�\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			system("cls");
			game(); break;
		case EXIT:
			system("cls"); printf("�˳���Ϸ\n"); break;
		default:
			system("cls"); printf("����������������:>\n"); break;
		}
	} while (input);
	return 0;
}