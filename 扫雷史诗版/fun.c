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
void find_mine(char show[][COLS],char mine [][COLS], int r, int c)//�����ܲ������Ż���
{
	int x = 0;
	int y = 0;
	char ch = 0;
	while (1)
	{
		printf("��������Ҫ�Ų��λ��,��ѡ���Ƿ�Ըõ���б�ʶ(Y\\����Ĭ�ϲ����)>");//��ͬһ�����α�ǻ�ȡ����ǣ�
		scanf("%d %d %c", &x, &y,&ch);
		if (x >= 1 && x <= r && y >= 1 && y <= c)//����Ϸ�
		{ 
			if (!is_find(show, x, y))//δ���Ų��
			{
				if (show[x][y] == 'M' && 'Y' == ch)
				{		show[x][y] = '*';
				printf("ȡ����ǳɹ�\n");
				system("cls");
				display_board(show,r,c);
				break;
			    }
				if ('Y' == ch)//�ж�һ���Ƿ���Ҫ��ǣ�
				{
					show[x][y] = 'M';
					printf("��ǳɹ�\n");
					system("cls");
					display_board(show, r, c);
					break;
				}
				else
				{
					if ('Y' == ch)
					{
						printf("�벻Ҫ���Ѿ��Ų���ĵ���б��\a\a\a\n");
						printf("����������\n");
						break;
					}
					else
					{
						if (is_mine(mine, x, y))
						{
							printf("�㱻��ը����\n\a\a\a");
							show[x][y] = '@';
							flag = 0;
							system("cls");
							display_board(mine, r, c);
							break;
						}
						else//������
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
				printf("�������Ų��,����������:>\n");
			}

		}
		else
			printf("����Ƿ�,����������\n");
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
	if (!(x >= 1 && x <= r && y >= 1 && y <= c))//��ֹԽ�磻
		return;
	if (is_mine(mine, x, y) ||is_find(show, x, y))//��չ����������1��û���Ų����2���Ų�λ�ò�����
		return;
	setp--;
	int count = get_mine(show, mine, x, y);//3���Ų�λ����Χû���ף�
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