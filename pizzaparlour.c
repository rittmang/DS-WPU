/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE-D
Batch: D4
Roll: 203460
Assignment: 5 (Pizza Parlour using Simple Queue)
*/

#define LENGTH 24
#define MAX 5
#include<stdio.h>
#include<stdlib.h>//for rand()
#include<time.h>//for system time capture
#include<string.h>//for above

typedef struct{
  char name[LENGTH];
  int order_id;
  long int mob_no;
  double amount;
  char c_time_string[LENGTH];
}Customer;    //Customer structure, c_time_string holds the System time captured.

typedef struct{
  Customer N[MAX];
  int f,r;
}Queue; //Queue structure, consisting of the array, front & rear indices

void enqueue(Queue* q, Customer k)//method to add an order to rear of Queue
{
  if(q->r==MAX-1)
    {printf("Queue Overflow\n\n");return;}

  if(q->f==-1)
    q->f=q->f+1;

  q->N[++q->r]=k;

}

Customer dequeue(Queue* q)//method to deliver an order from front of Queue
{
  if(q->f==-1 || q->r==-1 || q->f>q->r)
    {//printf("Queue Underflow");
    Customer returns;
    returns.name[0]='?';
    returns.name[1]='\0';
    returns.order_id=999999999;
    returns.mob_no=0000000000;
    returns.amount=00.00;
    returns.c_time_string[0]='\0';
    return returns;  }
  else
  {

    Customer val=q->N[q->f++];
    if(q->f==q->r+1){q->f=-1;q->r=-1;}
    return val;
  }
}

void display(Queue* q)//method to display order details of the orders in Queue
{
  printf("\n\n");
  if(q->f==-1)
    {printf("NO PENDING ORDERS\n\n----------------------------------------------\n");return;}
  for(int i=q->f;i<=q->r;i++)
  {
    printf("Customer Name=%s, Generated Order ID=%d, Mobile Number=%ld, Amount=%.2f, Time=%s\n",q->N[i].name,q->N[i].order_id,q->N[i].mob_no,q->N[i].amount,q->N[i].c_time_string);

  }
  printf("------------------------------------------------------------\n\n");
}
void status(Queue* q)//method to display current values of front and rear indices
{
  printf("\nfront=%d\trear=%d\n",q->f,q->r);
}
int main()
{
  Queue q;Customer returns;
  q.f=-1;q.r=-1;//V.V. IMP
  int random_start=rand();

  int choice=0;
  do {
        printf("0. Exit\n1. New Order\n2. Serve Order\n");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1: printf("Enter Customer Name:");
                  Customer elem;
                  scanf("%s",elem.name);
                  elem.order_id=random_start++;
                  printf("Enter Customer Mobile Number:");
                  scanf("%ld",&elem.mob_no);
                  printf("Enter Amount:");
                  scanf("%lf",&elem.amount);

                  //this section evaluates current system time, sets it to a static string, and adds it to the current Customer order.
                  time_t current_time;
                  time(&current_time);
                  char* c_string=ctime(&current_time);
                  strcpy(elem.c_time_string,c_string);

                  enqueue(&q,elem);


                  //status(&q)
                  display(&q);
                  break;

          case 2: returns=dequeue(&q);
                  if(returns.name[0]=='?')
                    printf("No Customer\n");
                  else
                    {printf("Thanks for eating with us, %s! Your Order ID was=%d.\n\tYour Payment Method was charged ₹ %0.2f\n",returns.name,returns.order_id,returns.amount);
                    printf("._ \n,(  `-. \n,': `.   `. \n,` *   `-. \n,'  ` :+  = `.  `. \n,~  (o):  .,   `.  `. \n,'  ; :   ,(__) x;`.  ; \n,'  :'  itz  ;  ; ; _,-' \n.'O ; = _' C ; ;'_,_ ; \n,;  _;   ` : ;'_,-'   i' \n,` `;(_)  0 ; ','       : \n.';6     ; ' ,-'~ \n,' Q  ,& ;',-.' \n,( :` ; _,-'~  ; \n,~.`c _',' \n.';^_,-' ~ \n,'_;-'' \n,,~ \ni' \n:");

                  }
                  //status(&q);
                  display(&q);
                  break;
        }

  } while(choice!=0);


  return 0;
}
