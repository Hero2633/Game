#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

int main()
{
	Stack ST = { NULL,0,0 };
	assert(&ST);
	StackPush(&ST, 1);
	StackPush(&ST, 2);
	StackPush(&ST, 3);
	StackPop(&ST);
	StackPop(&ST);
	StackPop(&ST);
	StackPush(&ST, 4);
	/*printf("%d \n",( & ST)->a[1]);*/
	 printf("%d ", StackTop(&ST));
	while (!StackEmpty(&ST))
	{
		
		printf("%d ",( & ST)->a[(&ST)->top - 1]);
		StackPop(&ST);
	}
	
	return 0;
}