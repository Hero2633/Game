#define  _CRT_SECURE_NO_WARNINGS 0
#include"game.h"
#pragma warning (disable:6031)
#pragma comment(lib,"winmm.lib")
//1�����̣�չʾ��//��չʾ����Ҫ�����ж��Ƿ�������
//2����ʼ�����̺�չʾ��//�ո��ʾû��#��ʾ�ף�*��ʼ��չʾ��
//3����ӡһ�����̣�
//4�������ף�
//5���Ų��ף�(ע�ⴥ����ϲ)
int setp = ROW * COL - MINE_COUNT;//��¼������ಽ������setp����0�Ǳ�ʾ��ȫλ���Ѿ����꣬��ս�ɹ�
int flag = 1;//��ʾδ������ը����������Ϸ������ը����������Ϸ��flag=0����սʧ�ܣ�
IMAGE img[12];
void game()
{
    char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init_board(mine,ROW,COL,' ');//��ʼ��
	init_board(show, ROW, COL, '*');//��ʼ��
	 setp = ROW * COL - MINE_COUNT;//
	 flag = 1;//������Ϸ��
	set_mine(mine, ROW, COL, MINE_COUNT);//������
	draw_mine(mine);
	while (setp&&flag)
	{
		find_mine(show, mine, ROW, COL);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	initgraph(ROW * SIZE, COL * SIZE);
	//mciSendString("open BGM.mp3 ", NULL, 0, NULL);//������
	//mciSendString("play BGM.mp3 repeat", NULL, 0, NULL);//�������֣�ע�����ֺ�ͼ��Ҫ��Դ�ļ���ͬһ�ļ�����
eg:
	setbkcolor(WHITE);
	cleardevice();
	game();
	HWND p = GetHWnd();//��ȡ��Ϣ���ӵľ�����������Ϊ��Ϣ���ӵ�ID��
	int tmp = MessageBox(p, "��Ϸ�ѽ���!�Ƿ������", "��ʾ", MB_OKCANCEL);//������Ϣ�����ж���Ϸ�Ƿ����
	if (IDOK == tmp)
	{
		//mciSendString("close BGM.mp3 ", NULL, 0, NULL);//�ر�����
		goto eg;
	}
	else
	{
		//mciSendString("close BGM.mp3 ", NULL, 0, NULL);//�ر�����
		closegraph();//�ر�ͼ�ν���
		return 0;
	}
	system("pause");//��ֹͼ�ν���һ������
	return 0;
}