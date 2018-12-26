/*
Name: Ritom Gupta
Class: S.Y B.Tech CSE-D
Batch: D4
Roll: 203460
Assignment: 2 (Sparse Matrix Operations)
*/

#define max 50
#include<stdio.h>
void accept(int mat[max][max],int r,int c)//accepting elements of matrix
{
  printf("Enter elements:\n");
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      scanf("%d",&mat[i][j]);
    }
  }
}
void display(int mat[max][max],int r,int c)//displaying elements of matrix
{
  printf("Printing elements:\n");
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      printf("%d\t",mat[i][j]);
    }
    printf("\n");
  }
}
void display2(int mat[max][3],int r,int c)//displaying elements of sparse matrix
{
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      printf("%d\t",mat[i][j]);
    }
    printf("\n");
  }
}
void compact(int mat[max][max],int compmat[max][3],int r,int c,int displ)//displ=1, to display matrix, if 0, not
{
  compmat[0][0]=r;compmat[0][1]=c;int nonzero=0;

  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(mat[i][j]!=0)//for nonzero elements
      {
        nonzero++;
        compmat[nonzero][0]=i;
        compmat[nonzero][1]=j;
        compmat[nonzero][2]=mat[i][j];
      }
    }
  }
  compmat[0][2]=nonzero;
  if(displ=1)
    {display2(compmat,nonzero+1,3);}
  else return;
}

void transpose(int mat[max][3],int transp[max][3])//forming tranpose of sparse matrix
{
  int n,currentb;

  transp[0][0]=mat[0][1];
  transp[0][1]=mat[0][0];
  transp[0][2]=mat[0][2];

  if(mat[0][2]>0)
  {
    currentb=1;
    for(int i=0;i<mat[0][1];i++)
    {
      for(int j=1;j<=mat[0][2];j++)
      {
        if(mat[j][1]==i)
        {
          transp[currentb][0]=mat[j][1];
          transp[currentb][1]=mat[j][0];
          transp[currentb][2]=mat[j][2];
          currentb++;
        }
      }
    }
  }
  display2(transp,transp[0][2]+1,3);
}


void fasttranspose(int mat[max][3],int transp[max][3])//forming transpose of sparse matrix using fast transpose matrix
{
  int rowTerms[max],startingPos[max];//max here would mean, number of columns in original matrix never exceeds matrix
  int numCols=mat[0][1],numTerms=mat[0][2];

  transp[0][0]=numCols;
  transp[0][1]=mat[0][0];
  transp[0][2]=numTerms;

  if(numTerms>0)
  {
    for(int i=0;i<numCols;i++)
      rowTerms[i]=0;

    for(int i=1;i<=numTerms;i++)
      rowTerms[mat[i][1]]++;

    startingPos[0]=1;

     for(int i=1;i<numCols;i++)
       startingPos[i]=startingPos[i-1]+rowTerms[i-1];

     for(int i=1;i<=numTerms;i++)
     {
       int j=startingPos[mat[i][1]]++;
       transp[j][0]=mat[i][1];
       transp[j][1]=mat[i][0];
       transp[j][2]=mat[i][2];
     }

     display2(transp,transp[0][2]+1,3);
  }
}
void add(int mat1[max][3],int r,int c)//input first array as already entered
{
  int normal_mat[max][max],mat2[max][3],mat3[max][3];//mat2 is the compact form of normal_mat, mat3 is addition result
  printf("Input Second Matrix:");
  accept(normal_mat,r,c);
  compact(normal_mat,mat2,r,c,0);
  printf("Finished Compacting");
  //add mat1 and mat2
  if(mat1[0][0]!=mat2[0][0] || mat1[0][1]!=mat2[0][1])
  {
    printf("INCONSISTENT MATRIX SIZES");return;
  }

  int tot1=mat1[0][2],tot2=mat2[0][2];int k1=1,k2=1,k3=1;

  while(k1<=tot1 && k2<=tot2)
  {
    if(mat1[k1][0]<mat2[k2][0])
    {
      mat3[k3][0]=mat1[k1][0];
      mat3[k3][1]=mat1[k1][1];
      mat3[k3][2]=mat1[k1][2];
      k3++;k1++;
    }
    else if(mat1[k1][0]>mat2[k2][0])
    {
      mat3[k3][0]=mat2[k2][0];
      mat3[k3][1]=mat2[k2][1];
      mat3[k3][2]=mat2[k2][2];
      k3++;k2++;
    }

    else if(mat1[k1][0]==mat2[k2][0])
    {
      if(mat1[k1][1]<mat2[k2][1])
      {
        mat3[k3][0]=mat1[k1][0];
        mat3[k3][1]=mat1[k1][1];
        mat3[k3][2]=mat1[k1][2];
        k3++;k1++;
      }
      else if(mat1[k1][1]>mat2[k2][1])
      {
        mat3[k3][0]=mat2[k2][0];
        mat3[k3][1]=mat2[k2][1];
        mat3[k3][2]=mat2[k2][2];
        k3++;k2++;
      }
      else
      {
        if((mat1[k1][2]+mat2[k2][2])!=0)
        {mat3[k3][0]=mat2[k2][0];
        mat3[k3][1]=mat2[k2][1];
        mat3[k3][2]=mat1[k1][2]+mat2[k2][2];
        k3++;k2++;k1++;}
        else
        {
          k2++;k1++;
        }
      }
    }
  }// end of while


  while(k1<=tot1)
  {
      mat3[k3][0]=mat1[k1][0];
      mat3[k3][1]=mat1[k1][1];
      mat3[k3][2]=mat1[k1][2];
      k3++;k1++;
  }
  while(k2<=tot2)
  {
    mat3[k3][0]=mat2[k2][0];
    mat3[k3][1]=mat2[k2][1];
    mat3[k3][2]=mat2[k2][2];
    k3++;k2++;
  }

  mat3[0][0]=mat1[0][0];
  mat3[0][1]=mat1[0][1];
  mat3[0][2]=k3-1;
  printf("\nADDITION RESULT:\n");
  display2(mat3,mat3[0][2]+1,3);
}

int main()
{
  printf("Enter number of rows and columns:\n");
  int r=0,c=0;
  scanf("%d%d",&r,&c);
  printf("Rows=%d, Columns=%d",r,c);
  int mat[max][max],compmat[max][3],transp[max][3],fast_transp[max][3];
  accept(mat,r,c);
  display(mat,r,c);
  printf("-----------\nCompact Form:\n");
  compact(mat,compmat,r,c,1);
  int choice=0;//get choice
  //-----------------------------------------------------------------------------

  do{
      printf("\n0. Exit\t1. Transpose\t2. Fast Transpose\t3. Add Input Matrix to\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:   printf("---------------\nTranspose:\n");
                  transpose(compmat,transp);
                  break;

        case 2:   printf("---------------\nFast Transpose:\n");
                  fasttranspose(compmat,fast_transp);
                  break;

        case 3:   printf("---------------\nAdding Input Matrix to:\n");
                  add(compmat,r,c);
                  break;

  }
}while(choice!=0);
  return 0;
}
