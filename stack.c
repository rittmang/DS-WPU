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
  if(isEmpty(s))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    char* popcorn;
    strcpy(popcorn,s->pile[s->top--]);
    return popcorn;
  }
}
void display(stack* s)
{
  for(int k=s->top;i>-1;i--)
    {
      printf("%s\n",s->pile[i]);
    }

}
int main()
{
  printf("\n\nSTACK OPERATIONS\n");
  int choice;
  stack s1;

  do{
      printf("0.Exit\n1.Push\n2.Pop\n3.Display");
      scanf("%d",&choice);
      char elem[MAX];
      switch(choice)
      {
        case 1: printf("Enter string:");
                scanf("%s",&elem);
                push(&s1,elem);
                break;

        case 2: printf("Popped Element:%s",pop(&s1));
                break;
      }

  }while(choice!=0);


}
