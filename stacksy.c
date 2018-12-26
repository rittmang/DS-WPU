#define MAX 30
#include<stdio.h>
#include<string.h>
#include<ctype.h>

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
  if(isEmpty(pile))
  {
    printf("Stack Underflow.");return "-999";
  }
  else
  {
    strcpy(popcorn,pile[top]);
    top--;
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
        top++;

        char st[20];
        st[0]=e[i];
        st[1]='\0';
        strcpy(pile[top],st);
      }
  }
  strcpy(str1,pop());
  printf("Infix expression=%s\n",str1);
}
void pospre(char e[MAX])
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  for(int i=0;e[i]!='\0';i++)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/')
      {
        strcpy(op1,pop());//get b
        strcpy(op2,pop());//get a

        str[0]=e[i];      //get +
        str[1]='\0';      //str=+

        strcat(str,op2);  //str=+a
        strcat(str,op1);  //str=+ab

        top++;
        strcpy(pile[top],str);
      }
      else
      {
        top++;

        char st[20];
        st[0]=e[i];
        st[1]='\0';
        strcpy(pile[top],st);
      }
  }
  strcpy(str1,pop());
  printf("Prefix expression=%s\n",str1);
}

void prein(char e[MAX])
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  //e=strrev(e);
  int l1=strlen(e);
  for(int i=l1;i>=0;i--)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/')
      {
        strcpy(op1,pop());
        strcpy(op2,pop());
        str[0]='(';
        str[1]='\0';

        strcat(str,op1);

        int l=strlen(str);
        str[l]=e[i];
        str[l+1]='\0';
        strcat(str,op2);

        l=strlen(str);
        str[l]=')';
        str[l+1]='\0';

        top++;
        strcpy(pile[top],str);
      }
      else
      {
        top++;

        char st[20];
        st[0]=e[i];
        st[1]='\0';
        strcpy(pile[top],st);
      }
  }
  strcpy(str1,pop());
  printf("Infix expression=%s\n",str1);
}

void prepost(char e[MAX])
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  int l1=strlen(e);
  for(int i=l1;i>=0;i--)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/')
      {
        strcpy(op1,pop());
        strcpy(op2,pop());

        str[0]='\0';//as was appending to str of previous iteration.
        strcat(str,op1);strcat(str,op2);

        int l=strlen(str);
        str[l]=e[i];
        str[l+1]='\0';

        top++;
        strcpy(pile[top],str);
      }
      else
      {
        top++;

        char st[20];
        st[0]=e[i];
        st[1]='\0';
        strcpy(pile[top],st);
      }
  }
  strcpy(str1,pop());
  printf("Postfix expression=%s\n",str1);
}

//-------------------------------------------
//INFIX SECTION BEGINS, USING A CHARACTER STACK, INSTEAD OF A STRING STACK

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

char stack[MAX];
int top2=-1;

void inpos(char e[MAX])
{
    char x;int i=0;

    while(e[i] != '\0')
    {
        if(isalnum(e[i]))
            printf("%c",e[i]);

        else if(e[i] == '(')
        {
          top2++;
          stack[top2]=e[i];
        }
        else if(e[i] == ')' && top2>=0)
        {
            while((x=stack[top2--]) != '(')
                printf("%c", x);
        }
        else if(top2>=0)
        {
            while(priority(stack[top2]) >= priority(e[i]))
                printf("%c",stack[top2--]);
                
            top2++;stack[top2]=e[i];
        }
        i++;
    }
    while(top2 != -1)
    {
        printf("%c",stack[top2--]);
    }
}

int main()
{
  printf("\n\nEXPRESSION CONVERSIONS\n");
  int choice;
  char exp[MAX];
  do{
      printf("\n0.Exit\n1.Postfix to Infix\n2.Postfix to Prefix\n3. Prefix to Infix\n4. Prefix to Postfix\n5. Infix to Postfix\n");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("\n\nEnter postfix expression:");
                scanf("%s",exp);
                posin(exp);
                printf("\n-------------\n");
                break;

        case 2: printf("\n\nEnter postfix expression:");
                scanf("%s",exp);
                pospre(exp);
                printf("\n-------------\n");
                break;

        case 3: printf("\n\nEnter prefix expression:");
                scanf("%s",exp);
                prein(exp);
                printf("\n-------------\n");
                break;

        case 4: printf("\n\nEnter prefix expression:");
                scanf("%s",exp);
                prepost(exp);
                printf("\n-------------\n");
                break;

        case 5: printf("\n\nEnter infix expression (with brackets):");
                scanf("%s",exp);
                inpos(exp);
                printf("\n-------------\n");
                break;
      }
  }while(choice!=0);

}
