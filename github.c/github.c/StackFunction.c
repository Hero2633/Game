#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void StackInit(Stack* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;

   
}


void StackPush(Stack* ps, STDataType data)
{
    assert(ps);
    int tmp = 9;
    if (ps->top == ps->capacity)
    {
         tmp = ps->capacity == 0 ? 4 : ps->capacity *2;
        STDataType* h = (STDataType*)realloc(ps->a, sizeof(STDataType) * tmp);
        if (h == NULL)
        {
            perror("StackPush\n");
            return;
        }
        ps->a = h;

    }ps->capacity = tmp;
    (ps->a)[ps->top] = data;
    ps->top++;
}

void StackPop(Stack* ps)
{
    assert(ps);
    assert(ps->top>0);
    ps->top--;
}
int StackSize(Stack* ps)
{
    assert(ps);
    return ps->top;
  }
int StackEmpty(Stack* ps)
{
    assert(ps);
    return ps->top == 0;
}

STDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(ps->top>0);
    return ps->a[ps->top - 1];
}
void StackDestroy(Stack* ps)
{
    assert(ps);
    free(ps->a);
    ps->capacity = 0;
    ps->top = 0;

}
