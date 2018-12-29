#define MAX 5
#include<stdio.h>

typedef struct{
  int N[MAX];
  int f,r;
}Queue;

void enqueue(Queue* q, int k)
{
  if(q->r==MAX-1)
    {printf("Queue Overflow\n\n");return;}

  if(q->f==-1)
    q->f=q->f+1;

  q->N[++q->r]=k;
}

int dequeue(Queue* q)
{
  if(q->f==-1 || q->r==-1 || q->f>q->r)
    {printf("Queue Underflow");return -999;}
  else
  {

    int val=q->N[q->f++];
    if(q->f==q->r+1){q->f=-1;q->r=-1;}
    return val;
  }
}

void display(Queue* q)
{
  printf("\n\n");
  for(int i=q->f;i<=q->r;i++)
  {
    printf("%d ",q->N[i]);
  }/* condition */
  printf("\n\n");
}
void status(Queue* q)
{
  printf("\nfront=%d\trear=%d\n",q->f,q->r);
}
int main()
{
  Queue q;
  q.f=-1;q.r=-1;

  int choice=0;
  do {
        printf("0. Exit\n1. Enqueue\n2.Dequeue\n");
        scanf("%d",&choice);

        switch(choice)
        {
          case 1: printf("Enter element:");
                  int elem;
                  scanf("%d",&elem);
                  enqueue(&q,elem);
                  status(&q);
                  display(&q);
                  break;

          case 2: printf("Dequeued element=%d",dequeue(&q));
                  status(&q);
                  display(&q);
                  break;
        }
  } while(choice!=0);


  return 0;
}
