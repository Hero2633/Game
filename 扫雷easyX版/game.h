#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<graphics.h>
#include<windows.h>
#include<mmsystem.h>
#define SIZE 50//����ÿ��ͼ��Ĵ�С��ͼ�ν���Ĵ�С
#define MINE_COUNT 10//��������
#define ROW 9//
#define COL 9//�����������任�Ѷȣ�
#define ROWS ROW+2
#define COLS COL+2
enum CHOOSE
{
	EXIT,
	PLAY,
};
extern int flag;
extern int setp;
extern IMAGE img[12];//�洢12�Ų�ͬ��ͼ��
void init_board(char a[][COLS], int r, int c, char set);//��ʼ������
void set_mine(char mine[][COLS], int r, int c,int count);//������
void find_mine(char show[][COLS], char mine[][COLS], int r, int c);//�Ų��ף�
int get_mine(char show[][COLS], char mine[][COLS], int r, int c);//�õ��׵�����
bool is_mine(char mine[][COLS], int x, int y);//�ж���x��y�Ƿ�Ϊ�ף�
bool is_find(char show[][COLS], int x, int y);//�ж��Ƿ��Ų��
void surprise(char mine[][COLS], char show[][COLS], int r, int c, int x, int y);//չ��һƬ
void draw_mine(char mine[][COLS]);//�滭����