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
    top++;
    strcpy(pile[top],elem);
  }
}
char* pop()
{
  char popcorn[MAX];
  printf("In function");
  if(isEmpty(pile))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    strcpy(popcorn,pile[top]);
    printf("\nTOP=%d",top);
    printf("\nPOPPED=%s\n",popcorn);
    top--;

    return popcorn;
  }
}
void display()
{
  int temp=top;
  for(int k=temp;k>=0;k--)
    {
      printf("%s\n",pile[k]);
    }
    printf("\nTOP=%d",top);
}
void posin(char e[20])
{
  char str[20];
//  for(int i=0;e[i]!='\0';i++)
  //{

  //}
}
int main()
{
  printf("\n\nSTACK OPERATIONS\n");
  int choice;
  char exp[20];
  char elem[MAX];
  do{
      printf("\n0.Exit\n1.Push\n2.Pop\n3.Display");
      scanf("%d",&choice);

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
