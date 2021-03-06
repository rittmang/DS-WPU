/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE-D
Batch: D4
Roll: 203460
Assignment: 4 (Expression Conversion using STACK)
*/

#define MAX 30
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char pile[MAX][MAX];  //STACK ARRAY
int top=-1;           //initial condition

int isFull()          //Returns 1 if pile is full else 0
{
  if(top==MAX-1)
    return 1;
  else return 0;
}
int isEmpty()         //Returns 1 if pile is empty else 0
{
  if(top==-1)
    return 1;
  else return 0;
}
void push(char elem[20])    //Not really used
{
  if(isFull())
  {
    printf("Stack OverFlow.");return;
  }
  else
  {
    top++;
    strcpy(pile[top],elem);
  }
}
char* pop()                //pops string element
{
  char *popcorn;
  if(isEmpty())
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

void posin(char e[MAX])//converts postfix expression to infix
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  for(int i=0;e[i]!='\0';i++)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' || e[i]=='^')
      {
        strcpy(op1,pop());//get operands
        strcpy(op2,pop());
        str[0]='(';//start making expression
        str[1]='\0';

        strcat(str,op2);// get (a

        int l=strlen(str);
        str[l]=e[i];//add operator, .: get (a+
        str[l+1]='\0';
        strcat(str,op1);//.: get (a+b

        l=strlen(str);
        str[l]=')';//.: get (a+b)
        str[l+1]='\0';
        top++;
        strcpy(pile[top],str);//push (a+b)
      }
      else
      {
        top++;

        char st[20];
        st[0]=e[i];//make a string of the operand
        st[1]='\0';
        strcpy(pile[top],st);//push it to stack
      }
  }
  strcpy(str1,pop());//final pop, get output into str1
  printf("Infix expression=%s\n",str1);//print str1
}
void pospre(char e[MAX])
{
  char str[MAX],op1[MAX],op2[MAX],st[MAX],str1[MAX];
  for(int i=0;e[i]!='\0';i++)
  {
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' || e[i]=='^')
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
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' || e[i]=='^')
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
      if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' || e[i]=='^')
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

int ICP(char x,int n)//Incoming Priority Table
{

    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
    if(x == ')' || x=='(')
        return  4;
    if(x=='^')
    {
      if(n==0)return 5;
      else return 6;
    }
    else return -1;
}
int ISP(char x,int n)//In-Stack Priority Table
{
  if(x == ')' || x=='(')
      return  0;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
    //if(x == ')' || x=='(')
      //  return  4;
    if(x=='^')
      {
          if(n==0)return 6;
          else return 5;
      }
    else return -1;
}
char stack[MAX];
int top2=-1;

void inpos(char e[MAX])
{
    char x;int i=0;

    while(e[i] != '\0')
    {
        if(isalnum(e[i]))               //i.e operand
            printf("%c",e[i]);

        else if(e[i] == '(')            //start of new sub-expression
        {
          top2++;
          stack[top2]=e[i];
        }
        else if(e[i] == ')' && top2>=0) //end of sub-expression
        {
            while((x=stack[top2--]) != '(')
                printf("%c", x);
        }
        else
        {
            while(ISP(stack[top2],1) >= ICP(e[i],1))//evaluate priority, push into stack
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
void inpre(char e[MAX])
{
    char x;int i=0;
    int l=strlen(e);
    char result[MAX];
    l--;
    while(l >= 0)
    {
        if(isalnum(e[l]))
            result[i++]=e[l];

        else if(e[l] == ')')
        {
          top2++;
          stack[top2]=e[l];
        }
        else if(e[l] == '(')
        {
            while((x=stack[top2--]) != ')')
                result[i++]=x;
        }
        else
        {
            while(ISP(stack[top2],0) >= ICP(e[l],0)){
                //printf("%c",stack[top2--]);
                result[i++]=stack[top2--];}

            top2++;stack[top2]=e[l];
        }
        l--;
    }
    while(top2>=0)
    {

        result[i++]=stack[top2--];
    }
    //result[++i]='\0';

    for(int i=strlen(result)-1;i>=0;i--)
      printf("%c",result[i]);

}
int main()//main function
{
  printf("\n\nEXPRESSION CONVERSIONS\n");
  int choice;
  char exp[MAX];
  do{
      printf("\n0.Exit\n1.Postfix to Infix\n2.Postfix to Prefix\n3. Prefix to Infix\n4. Prefix to Postfix\n5. Infix to Postfix\n6. Infix to Prefix\n");
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

        case 6: printf("\n\nEnter infix expression (with brackets):");
                scanf("%s",exp);
                inpre(exp);
                printf("\n-------------\n");
                break;

      }
  }while(choice!=0);

}
