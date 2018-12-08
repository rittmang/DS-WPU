/*
Name: Ritom Gupta
Division: 4
Batch: D4
Subject: DS-I
*/
#include<stdio.h>

typedef struct{		//define student of type struct with these 4 parameters
    char name[80];
    int roll;
    char city[80];
    float perc;
}student;

void display(student stude[],int n)//display function for entire array/collection
{
  for(int i=0;i<n;i++)
  {
    printf("\nName=%s",stude[i].name);
    printf("\tRoll=%d",stude[i].roll);
    printf("\tCity=%s",stude[i].city);
    printf("\tPercentage=%f",stude[i].perc);
    
  }
}
void display1(student stude[],int i)//display function for only 1 record
{
    printf("\nName=%s",stude[i].name);
    printf("\tRoll=%d",stude[i].roll);
    printf("\tCity=%s",stude[i].city);
    printf("\tPercentage=%f",stude[i].perc);
}

int search (student stude[],int r,int n)//performs linear search on entire array
{
  for(int i=0;i<n;i++)
  {
    if(stude[i].roll==r)//finds roll number 'r' in array
    {
    	display1(stude,i);
    	return i;
    }
  }
  return -1;
}
int bsearch(student stude[],int r,int n)//performs binary search on entire array
{
  insertionsort(stude,n);//first perform insertion sort
  printf("Sorted DataBase:\n");
  display(stude,n);
  printf("\n---");
  int l=0,u=n-1,flag=0;
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
int bsearchrec(student stude[],int l,int u,int r,int n)//performs binary search recursively, need to pass sorted array beforehand
{
	if(l<=u)
	{
		int mid = l + (r - l)/2;
		
		if (stude[mid].roll == r)  return mid; 
		
        if (stude[mid].roll > r) return bsearchrec(stude, l, mid-1, r, n); 
  
        return bsearchrec(stude, mid+1, u, r,n);  
	}
	return -1;
}

void selectionsort(student stude[],int n)//performs selection sort on array
{
  student temp[n];
  
  for(int i=0;i<n;i++)
  {
  	temp[i]=stude[i]; //create a temprary duplicate database  	
  }
  int k=0,min=0;
  for(int i=0;i<n-1;i++)
  {
    k++;printf("\n\n*****PASS %d",k);//print number of passes
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(temp[min].roll>temp[j].roll)
      {min=j;}//get minimum element in each pass
    }
    
    if(min!=i){   
        student tempr= temp[min];
        temp[min]=temp[i];
        temp[i]=tempr;}//put minimum element at start.
      
      display(temp,n);//print passes
    }
    
    
    printf("\n\nFinal Sorted Records:");
    display(temp,n);
}
void bubblesort(student stude[],int n)
{
  student temp[n];
  
  for(int i=0;i<n;i++)
  {
  	temp[i]=stude[i]; //create a temprary duplicate database  	
  }
  int k=0;
  for(int i=0;i<n-1;i++)
  {
    k++;printf("\n\n*****PASS %d",k);
    for(int j=0;j<n-1-i;j++)
    {
      if(stude[j+1].roll<stude[j].roll)//swap adjacent values
      {
        student tempr= temp[j];
        temp[j]=temp[j+1];
        temp[j+1]=tempr;
      }
      display(temp,n);
    }
    //display(temp,n);
  }
}

void insertionsort(student stude[],int n)
{
    int j, p,k=0;
    student tmp;
    for(p = 1; p < n; p++)
    {	k++;
    	
    	printf("\n\n*****PASS %d",k);
        tmp = stude[p];
        for(j = p; j > 0 && stude[j-1].roll > tmp.roll;j--)
          {  stude[j] = stude[j-1];display(stude,n);printf("\nShift---");}//shift values in sorted subarray
        stude[j] = tmp;//set new value in correct position
        display(stude,n);
    }
}
int unique(student stude[],int r,int lim)//determines if roll number input is unique
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
        
  perc: printf("\nEnter percentage=");//perc goto statement redirects here
        scanf("%f",&stud[i].perc);
        if(stud[i].perc<0 || stud[i].perc>100)
        {
        	printf("Enter % between 0 - 100");
        	goto perc;
        }
        printf("----------------------------");
   }
   display(stud,n);
   int cho;
   do {
     printf("\n1. Linear Search\t2. Binary Search\t3. Selection Sort\t4. Bubble Sort\t5. Insertion Sort\n6.Display Records");
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
              printf("Done\n\n");
              
              break;

      case 4: printf("Performing bubble sort:");
              bubblesort(stud,n);
              printf("Done\n\n");
              
              break;

      case 5: printf("Performing insertion sort:");
              insertionsort(stud,n);
              printf("Done\n\n");
              
              break;
      case 6: printf("\n\n--DISPLAY RECORDS:\n\n");
      	      display(stud,n);
      	      break;
     }
     printf("\n*********************************\n");
   } while(cho!=0);
}
