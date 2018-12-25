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
  char *popcorn;
  //printf("In function");
  if(isEmpty(pile))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    strcpy(popcorn,pile[top]);
    //printf("\nTOP=%d",top);
    //printf("\nPOPPED=%s\n",popcorn);
    top--;
    //popcorn=malloc(3);
    return popcorn;
  }
}

void posin(char e[MAX])
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  for(int i=0;e[i]!='\0';i++)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/')
      {
        strcpy(op1,pop());
        strcpy(op2,pop());
        str[0]='(';
        str[1]='\0';

        strcat(str,op2);

        int l=strlen(str);
        str[l]=e[i];
        str[l+1]='\0';
        strcat(str,op1);

        l=strlen(str);
        str[l]=')';
        str[l+1]='\0';

        top++;
        strcpy(pile[top],str);
      }
      else
      {
        //strcpy(st,"");
        top++;

        char st[20];
        st[0]=e[i];
        st[1]='\0';
        strcpy(pile[top],st);
      }
  }
  strcpy(str1,pop());
  printf("%s",str1);
}
int main()
{
  printf("\n\nEXPRESSION CONVERSIONS\n");
  int choice;
  char exp[MAX];
  do{
      printf("\n0.Exit\n1.Postfix to Infix\n");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("HELLO2");
                printf("\n\nEnter expression:");
                scanf("%s",exp);
                posin(exp);
                printf("\n-------------\n");
                break;

      }

  }while(choice!=0);

}
