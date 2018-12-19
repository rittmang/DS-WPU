#define MAX 30
#include<stdio.h>
#include<string.h>


char pile[MAX][MAX];
int top=-1;

int  isFull()
{
  if(top==MAX-1)
    return 1;
  else return 0;
}
int isEmpty()
{
  if(top==-1)
    return 1;
  else return 0;
}
void push(char elem[20])
{
  if(isFull(pile))
  {
    printf("Stack OverFlow.");return;
  }
  else
  {
    strcpy(pile[++top],elem);
  }
}
char* pop()
{
  printf("In function");
  if(isEmpty(pile))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    char* popcorn;
    strcpy(popcorn,pile[top--]);
    printf("TOP=%d",top);
    return popcorn;
  }
}
void display()
{
  for(int k=top;k>=0;k--)
    {
      printf("%s\n",pile[k]);
    }

}
int main()
{
  printf("\n\nSTACK OPERATIONS\n");
  int choice;

  do{
      printf("\n0.Exit\n1.Push\n2.Pop\n3.Display");
      scanf("%d",&choice);
      char* elem;
      switch(choice)
      {
        case 1: printf("\n\nEnter string:");
                scanf("%s",elem);
                push(elem);
                break;

        case 2: printf("\n\nPopped Element:%s",pop());
                break;

        case 3: printf("\n\nDisplaying Pile:\n");
                display();
                break;
      }

  }while(choice!=0);


}
