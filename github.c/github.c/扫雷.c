#define _CRT_SECURE_NO_WARNINGS
#include"game2.h"
void mean()
{
	printf("    ɨ��  \n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("��ѡ�����ѡ��:");
}
void game()
{
	char arr1[Hs][Ls] = { 0 };//���������ڲ����ף�
	char arr2[Hs][Ls] = { 0 };//�����������Ų��ף����ճ��ֵ�Ҳֻ�и����飻
	cssz(arr1,Hs,Ls,' ');//���ף�@
	cssz(arr2,Hs,Ls,'*');//���ף��� ��
	/*dyqp(arr1,H,L);*///��ӡ��ʼ���������̣�
	dyqp(arr2,H,L);
	bzdl(arr1, H, L);//��ʼ������ף�
	/*dyqp(arr1, H, L);*/
	while (1)
	{
		int x= 0,y=0;
		printf("�����������Ų������:");
		eg2:scanf("%d %d", &x,&y);
		int z = pcdl(arr1, x, y);
		if (x >= 1 && x < 10 && y >= 1 && y < 10)
		{
			if (arr2[x][y] == '*')
			{
				if (z == -1)
				{
					printf("���ź����ȵ�������,����,��Ϸ����\n\a\a\a");
					printf("��>>>>>\n");
					dyqp(arr1, H, L);
					break;
				}
				else
				{
					int a = pcdl(arr1, x, y);
					char f = 0;
					f = '0' + a;//������ת��Ϊ�ַ������确6��=��0��+6��
					arr2[x][y] = f;//��x��y����Χ���׿�����
					/*dyqp(arr1, H, L);*/
					dyqp(arr2, H, L);
				}
			}
			else
			{
				printf("��λ���ѱ�ռ������������:");
				goto eg2;
			}
		}
		else
		{
			printf("����������겻�Ϸ�������������:");
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
		printf("�˳�\n"); break;
	default:printf("����ѡ��δӵ��,����������:");
		goto eg1;
		break;
	}
	return 0;
}