#define MAX 30
#include<stdio.h>
#include<string.h>

typedef struct{
      char pile[MAX][MAX];
      int top;
  }stack;

int  isFull(stack *s)
{
  if(s->top==MAX-1)
    return 1;
  else return 0;
}
int isEmpty(stack *s)
{
  if(s->top==-1)
    return 1;
  else return 0;
}
void push(stack *s, char elem[20])
{
  if(isFull(s))
  {
    printf("Stack OverFlow.");return;
  }
  else
  {
    strcpy(s->pile[++s->top],elem);
  }
}
char* pop(stack *s)
{
  printf("In function");
  if(isEmpty(s))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    printf("In POPPING");
    char* popcorn;
    strcpy(popcorn,s->pile[s->top]);
    printf("STRING COPIED to popcorn");
    s->top--;
    printf("TOP=%d",s->top);
    return popcorn;
  }
}
void display(stack* s)
{
  for(int k=s->top;k>-1;k--)
    {
      printf("%s\n",s->pile[k]);
    }

}
int main()
{
  printf("\n\nSTACK OPERATIONS\n");
  int choice;
  stack s1;
  s1.top=-1;
  do{
      printf("\n0.Exit\n1.Push\n2.Pop\n3.Display");
      scanf("%d",&choice);
      char elem[MAX];
      switch(choice)
      {
        case 1: printf("\n\nEnter string:");
                scanf("%s",&elem);
                push(&s1,elem);
                break;

        case 2: printf("\n\nPopped Element:%s",pop(&s1));
                break;

        case 3: printf("\n\nDisplaying Pile:\n");
                display(&s1);
                break;
      }

  }while(choice!=0);


}
