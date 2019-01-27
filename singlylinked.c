#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int item;
  struct Node *next;
};
typedef struct Node Node;

void insertb(Node *first)//not working?
{
  Node *nn;

  nn=(Node *)malloc(sizeof(Node));
  printf("Enter integer:");
  scanf("%d",&nn->item);

  if(first==NULL){
    //nn->next=NULL;
  //  first=nn;
    first =nn;
    first->next=NULL;
  }
  else{
  nn->next=first;
  first=nn;}

  printf("In InsertB\n");
  //current->next=temp;
  //current=temp;

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

void insertPos(Node *first, int pos)
{
  Node *current=first->next, *temp=(Node *)malloc(sizeof(Node));

  printf("Enter integer:");
  scanf("%d",&temp->item);
  if(pos>noofnodes(first)+2)
    {printf("Cannot Insert");return;}
  temp->next=NULL;

  /*int i=0;


  while(i++!=pos)
  {
    current=current->next;
    temp->next=current->next;
    current->next=temp;
  }*/
  for(int i=1;i<pos-1;i++)
  {
    if(current->next=NULL)
    {
      printf("Less elements");
      return;
    }
    current=current->next;
  }
  temp->next=current->next;
  current->next=temp;

}
void reverse(Node *first)
{

  Node *current,*prev,*temp;
  if(first==NULL){printf("Empty");return;}
  else{

  while(current!=NULL)
  {
    temp=current->next;
    current->next=prev;
    prev=current;
    current=temp;
  }
  first->next=prev;
}
}
int main()
{
  Node *first;
  first=(Node*)malloc(sizeof(Node*));
  first->next=NULL;


  int choice=0;
  do {

    printf("0. Exit\n1. Insert Node At Beginning (Not working)\n2. Insert Node at End\n3. Display\n4. Number of Nodes\n5. Insert At Position\n6. Reverse List\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: insertb(first);
              break;

      case 2: first=inserte(first);
              break;

      case 3: display(first);
              break;

      case 4: printf("Number of nodes=%d\n",noofnodes(first));
              break;

      case 5: printf("Enter index:");int pos;
              scanf("%d",&pos);
              insertPos(first,pos);
              break;

      case 6: printf("Reversed the list\n");
              reverse(first);
              break;
    }

    printf("\n----------------------------\n");
  } while(choice!=0);
  return 0;
}
