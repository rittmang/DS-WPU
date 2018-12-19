#define MAX 30;
#include<stdio.h>

typedef struct{
      char pile[MAX][MAX];
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
    s.pile[++s.top]=elem;
  }
}
char[] pop(stack s)
{
  if(isEmpty(s))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    char[] popcorn=s.pile[s.top--];
    return popcorn;
  }
}
