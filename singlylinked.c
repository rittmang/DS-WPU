#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int item;
  struct Node *next;
};
typedef struct Node Node;

Node* insertb(Node *first)
{
  Node *nn, *pratham=first->next;

  nn=(Node *)malloc(sizeof(Node *));
  printf("Enter integer:");
  scanf("%d",&nn->item);

  if(pratham==NULL){

    pratham=nn;
    first->next=pratham;
    pratham->next=NULL;
  }
  else{
    first->next=nn;
    nn->next=pratham;
    pratham=nn;

  }
  return first;
}

Node* inserte(Node *first)
{
  char ch;
  do {

      Node *nn;
      nn=(Node*)malloc(sizeof(Node*));
      printf("Enter integer:");
      scanf("%d",&nn->item);
      nn->next=NULL;

      Node *current=first;
      while(current->next!=NULL)current=current->next;
      current->next=nn;

      printf("Add more nodes? Y:N");
      scanf(" %c",&ch);//maintain the space before %c

  } while(ch=='Y');

  return first;
}
void display(Node *first)
{
  if(first->next==NULL)printf("EMPTY LIST\n");

  else{

    Node *current=first->next;

    while(current!=NULL)
    {
      if(current->next!=NULL)
        printf("%d--->",current->item);
      else
        printf("%d---|",current->item);
      current=current->next;
    }
    printf("\n");
  }
}
int noofnodes(Node *first)
{
  Node *current=first;int i=0;
  while(current->next!=NULL)
  {
    i++;
    current=current->next;
  }
  return i;
}

Node* insertPos(Node *first, int pos)
{
  if(pos>noofnodes(first)+1)
    {printf("Cannot Insert");return first;}

  Node *current=first->next, *temp=(Node *)malloc(sizeof(Node *));

  printf("Enter integer:");
  scanf("%d",&temp->item);


  int counter=1;
  if(pos==counter)
  {
    first->next=temp;
    temp->next=current;
  }
  while(current!=NULL)
  {
    if(counter==pos-1)
    {
      Node *nd=current->next;
      current->next=temp;
      temp->next=nd;
      break;
    }
    else
    {
      counter++;
      current=current->next;
    }
  }
  return first;
}
Node* reverse(Node *first)
{

  Node *current=first->next,*prev=NULL,*temp;
  if(first==NULL){printf("Empty");return first;}

  else{

  while(current!=NULL)
  {
    temp=current->next;
    current->next=prev;
    prev=current;
    current=temp;
  }
  first->next=prev;
  return first;
}
}
int main()
{
  Node *first;
  first=(Node*)malloc(sizeof(Node*));
  first->next=NULL;


  int choice=0;
  do {

    printf("0. Exit\n1. Insert Node At Beginning\n2. Insert Node at End\n3. Display\n4. Number of Nodes\n5. Insert At Position\n6. Reverse List\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: first=insertb(first);
              display(first);
              break;

      case 2: first=inserte(first);
              display(first);
              break;

      case 3: display(first);
              break;

      case 4: printf("Number of nodes=%d\n",noofnodes(first));
              break;

      case 5: printf("Enter position:");int pos;
              scanf("%d",&pos);
              first=insertPos(first,pos);
              display(first);
              break;

      case 6: printf("Reversed the list\n");
              first=reverse(first);
              display(first);
              break;
    }

    printf("\n----------------------------\n");
  } while(choice!=0);
  return 0;
}
