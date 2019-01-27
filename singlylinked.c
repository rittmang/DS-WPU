#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int item;
  struct Node *next;
};

typedef struct Node Node;

Node* insertb(Node *first)//inserts Node at front of list
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

Node* inserte(Node *first)//inserts Node at end of list
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

  } while(ch=='Y');//while user inputs Y

  return first;
}

void display(Node *first)//display the list
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
int noofnodes(Node *first)//counts number of nodes
{
  Node *current=first;int i=0;
  while(current->next!=NULL)
  {
    i++;
    current=current->next;
  }
  return i;
}

Node* insertPos(Node *first, int pos)//add node at position
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

Node* deletePos(Node *first,int pos)//deletes Node from position
{
  if(pos>noofnodes(first))
    {printf("Cannot Delete\n");return first;}

  Node *current=first->next,*prev=first;
  int counter=1;

  while(current!=NULL)
  {
    if(counter==pos)
    {
      prev->next=current->next;
      free(current);
      break;
    }
    counter++;
    prev=current;
    current=current->next;

  }



  return first;
}
Node* reverse(Node *first)//reverses the list
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

Node* sort(Node *first)//sort elements of list using Bubble Sort logic
{
    int n,i,j;
    Node *temp,*prev,*curr;
    temp=first->next;
    n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    for(i=0;i<n;i++)
    {
        prev=first;
        curr=prev->next;
        for(j=0;j<n-1;j++)
        {
            temp=curr->next;
            if(curr->item>temp->item)
            {
                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }
    return first;
}

Node* merge(Node *first1,Node *first2,Node *first3)//merge lists first1 and first2, make new list at first3
{
    Node *c1,*c2,*c3;
    c1=first1->next;
    c2=first2->next;

    if(c1->item>c2->item)
    {
        first3->next=c2;
        c2=c2->next;
        c3=first3->next;
    }
    else
    {
        first3->next=c1;
        c1=c1->next;
        c3=first3->next;
    }
    while(c1!=NULL && c2!=NULL)
    {
        if(c1->item>c2->item)
        {

            c3->next=c2;
            c2=c2->next;
            c3=c3->next;
        }
        else
        {
            c3->next=c1;
            c1=c1->next;
            c3=c3->next;
        }
    }
    while(c1!=NULL)
    {
        c3->next=c1;
        c1=c1->next;
        c3=c3->next;
    }
    while(c2!=NULL)
    {
        c3->next=c2;
        c2=c2->next;
        c3=c3->next;
    }
    return first3;
}

int main()
{
  Node *first,*first2,*first3;
  first=(Node*)malloc(sizeof(Node*));  first->next=NULL;
  first2=(Node*)malloc(sizeof(Node*));  first2->next=NULL;
  first3=(Node*)malloc(sizeof(Node*));  first3->next=NULL;

  int choice=0;
  loop:do {

    printf("0. Exit\n1. Insert Node At Beginning\n2. Insert Node at End\n3. Display\n4. Number of Nodes\n5. Insert At Position\n6. Reverse List\n7. Sort Nodes\n8. Merge Current with another list\n9. Delete node in list\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 0: break;

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

      case 7: printf("Sorting the list\n");
              first=sort(first);
              display(first);
              break;


      case 8: if(first->next==NULL)
              {
                printf("Fill current list first.\n");
                printf("\n----------------------------\n");
                goto loop;
              }
              first=sort(first);

              printf("Enter elements for List2:\n");
              first2=inserte(first2);
              printf("\n~~~~~~~~~~~~~~\n");
              first2=sort(first2);

              printf("\n\n\nThe lists (sorted) are:\n\n\n");
              display(first);printf("\n&\n");display(first2);

              first3=merge(first,first2,first3);

              printf("\n\nLists have been merged to give:\n\n");
              first=first3;
              display(first);
              break;

      case 9:
              printf("Enter position:");
              scanf("%d",&pos);
              first=deletePos(first,pos);
              display(first);
              break;
      default:
              printf("\n(-_-)\n");



    }

    printf("\n----------------------------\n");
  } while(choice!=0);
  return 0;
}
