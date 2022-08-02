#define  _CRT_SECURE_NO_WARNINGS 0
#include"game.h"
#pragma warning (disable:6031)
#pragma comment(lib,"winmm.lib")
//1、雷盘，展示盘//（展示盘主要用来判断是否被侦察过）
//2、初始化雷盘和展示盘//空格表示没雷#表示雷；*初始化展示盘
//3、打印一下棋盘；
//4、布置雷；
//5、排查雷；(注意触发惊喜)
int setp = ROW * COL - MINE_COUNT;//记录排雷最多步数；当setp等于0是表示安全位置已经排完，挑战成功
int flag = 1;//表示未被地雷炸死而结束游戏，地雷炸死而结束游戏的flag=0，挑战失败；
IMAGE img[12];
void game()
{
    char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init_board(mine,ROW,COL,' ');//初始化
	init_board(show, ROW, COL, '*');//初始化
	 setp = ROW * COL - MINE_COUNT;//
	 flag = 1;//重置游戏；
	set_mine(mine, ROW, COL, MINE_COUNT);//布置雷
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
	//mciSendString("open BGM.mp3 ", NULL, 0, NULL);//打开音乐
	//mciSendString("play BGM.mp3 repeat", NULL, 0, NULL);//播放音乐，注意音乐和图标要和源文件在同一文件里面
eg:
	setbkcolor(WHITE);
	cleardevice();
	game();
	HWND p = GetHWnd();//获取消息盒子的句柄（可以理解为消息盒子的ID）
	int tmp = MessageBox(p, "游戏已结束!是否继续？", "提示", MB_OKCANCEL);//设置消息盒子判断游戏是否继续
	if (IDOK == tmp)
	{
		//mciSendString("close BGM.mp3 ", NULL, 0, NULL);//关闭音乐
		goto eg;
	}
	else
	{
		//mciSendString("close BGM.mp3 ", NULL, 0, NULL);//关闭音乐
		closegraph();//关闭图形界面
		return 0;
	}
	system("pause");//防止图形界面一闪而过
	return 0;
}