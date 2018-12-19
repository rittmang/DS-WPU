#define MAX 30;
#include<stdio.h>

typedef struct{
      char pile[MAX];
      int top=-1;
  }stack;

int  isFull(stack s)
{
  if(s.top==MAX-1)
    return 1;
  else return 0;
}
int isEmpty(stack s)
{
  if(s.top==-1)
    return 1;
  else return 0;
}
void push(stack s, char elem[20])
{
  if(isFull(s))
  {
    printf("Stack OverFlow.");return;
  }
  else
  {
    s.pile[++top]=elem;
  }
}
