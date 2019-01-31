#include<stdio.h>

typedef struct{
    char name[80];
    int roll;
    char city[80];
    float perc;
}student;

void display(student stude[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("\nName=%s",stude[i].name);
    printf("\tRoll=%d",stude[i].roll);
    printf("\tCity=%s",stude[i].city);
    printf("\tPercentage=%f",stude[i].perc);

  }
}
void display1(student stude[],int i)
{
	printf("\nName=%s",stude[i].name);
    printf("\tRoll=%d",stude[i].roll);
    printf("\tCity=%s",stude[i].city);
    printf("\tPercentage=%f",stude[i].perc);
}

int search (student stude[],int r,int n)
{
  for(int i=0;i<n;i++)
  {
    if(stude[i].roll==r)
    {
    	display1(stude,i);
    	return i;
    }
  }
  return -1;
}
int bsearch(student stude[],int r,int n)
{
  insertionsort(stude,n);
  printf("Sorted DataBase:\n");
  display(stude,n);
  printf("\n---");
  int l=0,u=n-1;
  while(l<=u)
  {
    int mid=(l+u)/2;

    if(r>stude[mid].roll)
      l=mid+1;

    else if(r<stude[mid].roll)
      u=mid-1;

    else if (r==stude[mid].roll)
      {
        display1(stude,mid);
      	return mid;
      }
  }
  return -1;
}

void selectionsort(student stude[],int n)
{
  int min=0;

  for(int i=0;i<n-1;i++)
  {
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(stude[min].roll>stude[j].roll)
        min=j;
    }
      if(min!=i)
      {
        student temp= stude[min];
        stude[min]=stude[i];
        stude[i]=temp;
      }
    }
  }

void bubblesort(student stude[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
    {
      if(stude[j+1].roll<stude[j].roll)
      {
        student temp= stude[j];
        stude[j]=stude[j+1];
        stude[j+1]=temp;
      }
    }
  }
}

void insertionsort(student stude[],int n)
{
    int j, p;
    student tmp;
    for(p = 1; p < n; p++)
    {
        tmp = stude[p];
        for(j = p; j > 0 && stude[j-1].roll > tmp.roll;j--)
            stude[j] = stude[j-1];
        stude[j] = tmp;
    }
}
int unique(student stude[],int r,int lim)
{
	for(int i=0;i<=lim;i++)
	{
		if(stude[i].roll==r)
			return 0;
	}
	return 1;
}

int main() {
   int n;
   printf("Enter number of students=\n");
   scanf("%d",&n);
   student stud[n];

   for(int i=0;i<n;i++)
   {
        printf("\nEnter name=");
        scanf("%s",&stud[i].name);
  roll: printf("\nEnter roll=");// goto statement redirects here
        scanf("%d",&stud[i].roll);
        if(!unique(stud,stud[i].roll,i-1))
        {
        		printf("Inputted roll number exists. Re-enter roll number");
        		goto roll;
        }
        printf("\nEnter city=");
        scanf("%s",&stud[i].city);
        printf("\nEnter percentage=");
        scanf("%f",&stud[i].perc);
        printf("----------------------------");
   }
   display(stud,n);
   int cho;
   do {
     printf("\n1. Linear Search\t2. Binary Search\t3. Selection Sort\t4. Bubble Sort\t5. Insertion Sort\n");
     scanf("%d",&cho);
     int r,res;
     switch(cho)
     {
       case 1: printf("\nEnter rollnumber to search=\n");
               scanf("%d",&r);
               res=search(stud,r,n);
               if(res>=0)printf("\nFound at index %d",res);
               else printf("\nNot found.");
               break;

       case 2: printf("\nEnter rollnumber to search=\n");
               scanf("%d",&r);
               res=bsearch(stud,r,n);
               if(res>=0)printf("\nFound at index %d",res);
               else printf("\nNot found.");
               break;

      case 3: printf("Performing selection sort:");
              selectionsort(stud,n);
              printf("Done");
              display(stud,n);
              break;

      case 4: printf("Performing bubble sort:");
              bubblesort(stud,n);
              printf("Done");
              display(stud,n);
              break;

      case 5: printf("Performing insertion sort:");
              insertionsort(stud,n);
              printf("Done");
              display(stud,n);
              break;
     }
     printf("\n*********************************\n");
   } while(cho!=0);
}
