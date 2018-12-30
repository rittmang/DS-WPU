#define MAX 5
#define MAXIMUM(x, y) (((x) > (y)) ? (x) : (y))
#define MINIMUM(x, y) (((x) < (y)) ? (x) : (y))
#include<stdio.h>

typedef struct{
  int N[MAX];
  int f,r;
}Queue;

void enqueue(Queue* q, int k)
{
  /*if((q->f==0 && q->r==MAX-1) || (q->f > (q->r+1)  ))
    {printf("Queue Overflow\n\n");return;}*/
    if((q->f==0 && q->r==MAX-1) || (q->r == (q->f-1)%(MAX-1)  ))
      {printf("Queue Overflow\n\n");return;}


    else if(q->f==-1){
      q->f=q->r=0;
      q->N[q->r]=k;
    }

    else if(q->r==MAX-1 && q->f!=0){
      q->r=0;
      q->N[q->r]=k;
    }
    else
    {
      q->N[++q->r]=k;
    }
}

int dequeue(Queue* q)
{
  /*if(q->f==-1 || q->r==-1 || q->f>q->r)
    {printf("Queue Underflow");return -999;}*/

    if(q->f==-1)
      {printf("Queue Underflow");return -999;}

    int val=q->N[q->f];

    q->N[q->f]=-1;

    if(q->f==q->r){q->f=q->r=-1;}

    else if(q->f==MAX-1){q->f=0;}

    else q->f++;

    return val;

}

void display(Queue* q)
{
  printf("\n\n");
  if(q->f==-1){printf("\nEMPTY QUEUE\n");return;}

  if(q->r>=q->f)
  {
    for(int i=q->f;i<=q->r;i++)
    {
      printf("%d ",q->N[i]);
    }
  }
  else
  {
    for (int i = q->f; i < MAX; i++)
      printf("%d ", q->N[i]);

    for (int i = 0; i <= q->r; i++)
      printf("%d ", q->N[i]);
  }
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
