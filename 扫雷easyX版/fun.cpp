#define  _CRT_SECURE_NO_WARNINGS 0
#include "game.h"
#pragma comment(lib,"winmm.lib")
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
	MOUSEMSG msg;
	while (1)
	{
			msg = GetMouseMsg();//��ȡ������Ϣ��
			y = msg.x / SIZE + 1;
			x = msg.y / SIZE + 1;//ע�������������������ת����������������ĺ�����*SIZE���������������꣩
			if (x >= 1 && x <= ROW && y >= 1 && y <= COL&&!is_find(show,x,y))//����Ϸ���δ���Ų��
			{
				switch (msg.uMsg)//����������ҵ�����Ϣ
				{
				case WM_LBUTTONDOWN://����򿪸���
				{
					if (is_mine(mine, x, y))//���׵Ļ�ֱ�ӽ�����Ϸ��
				{
					mciSendString("open mine.mp3", NULL, 0, NULL);
					putimage((y - 1) * SIZE, (x - 1) * SIZE, img + 11);
					mciSendString("play mine.mp3 ", NULL, 0, NULL);
					flag = 0;
					return;
				}
				else//�����׵Ļ������ܲ��ܴ�����ϲ��
				{
					surprise(mine, show, ROW, COL, x, y);
					return;
				}
				}break;
				case WM_RBUTTONDOWN://����һ���ʾ���
				{
					if (show[x][y] == 'M')
					{
						mciSendString("open Mouse.mp3", NULL, 0, NULL);
						show[x][y] = '*';
						putimage((y-1)*SIZE,(x-1)*SIZE,img+9);
						mciSendString("play Mouse.mp3 wait", NULL, 0, NULL);
						mciSendString("close Mouse.mp3", NULL, 0, NULL);
						return;
					}
					else
					{
						mciSendString("open Mouse.mp3", NULL, 0, NULL);
						show[x][y] = 'M';
						putimage((y - 1) * SIZE, (x - 1) * SIZE, img + 10);
						mciSendString("play Mouse.mp3 wait", NULL, 0, NULL);
						mciSendString("close Mouse.mp3", NULL, 0, NULL);
						return;
					}
				}break;
				}
			}
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
	putimage((y-1)*SIZE,(x-1)*SIZE,img+count);
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
void draw_mine(char mine[][COLS])
{
	char file[20] = "";
	for (int i = 0; i < 12; i++)
	{
		sprintf(file,"%d.jpg",i);
		loadimage(img+i,file,SIZE,SIZE);
	}
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{  
				putimage((j-1) * SIZE, (i-1) * SIZE, img + 9);
		}
	}
}