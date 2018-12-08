/*
Name: Ritom Gupta
Division: 4
Batch: D4
Subject: DS-I
*/
#include<stdio.h>

void accept(char *str)//to accept string
{
	scanf("%s",str);
}
void display(char str[])//to display string
{
	printf("%s\n",str);
}
int length(char *str)//to find length of string using pointers
{
	int l=0;
	while(*str!='\0')//till string reaches end
	{
		str++;
		l++;
	}
	return l;
}
void copy(char *a,char *b)//to copy string a to b
{
	while(*a != '\0')
	{
		*b=*a;
		a++;
		b++;
	}
	*b='\0';
}
int equal(char *a,char *b)//to find if string a = string b, returns 1 if yes, else 0
{
	while(*a==*b && *a!='\0')
	{
		a++;
		b++;
	}
	if(*a!='\0')return 0;
	else return 1;//equal in length and also character-by-character
}
void concatenate(char *a,char *b)//concatenate string a and b as a+b
{
	while(*a!='\0')a++;//reach end of first string

	while(*b!='\0')//till end of second string is reached
	{
		*a=*b;
		a++;
		b++;
	}
	*a='\0';
}

void reverse(char *a,char *b)//
{
	copy(a,b);
	int l=length(a);
	char *begin,*end,temp;

	begin=a;end=a;
	for(int i=0;i<l-1;i++)end++;

	for(int i=0;i<l/2;i++)
	{
		temp=*end;
		*end=*begin;
		*begin=temp;

		begin++;
		end--;
	}
}
void palindrome(char *a)
{
	char str1[20];
	reverse(a,str1);
	if(equal(a,str1)==1)printf("%s is a Palindrome.",str1);
	else printf("%s is not a Palindrome.",str1);

}
int match2(char *s, char *p, int overlap)	//used for determining substring with overlap
{
        int c = 0, l = length(p);

        while (*s != '\0') {
                if (compare2(s++, p, l)) continue;//comparing *s and *p, for l bytes
                if (!overlap) s += l - 1;
                c++;				//increment counter
        }
        return c;
}
int compare2(char *str1,char *str2,int n)//used for comparing only n bytes of str1 and str2
{
	for(int i=0;i<n;i++)
	{
		if(*str1!=*str2)
			return *str1-*str2;//return first difference in characters
		str1++;
		str2++;
	}
	return 0;
}
int compare(const char *str1,const char *str2)//regular compare for entire string
{
	while(*str1!='\0'){
		if(*str1!=*str2)
			return *str1-*str2;//return first difference in characters
		str1++;
		str2++;

	}

}
int freq(char *str,char c)
{
	int count=0;
	while(*str!='\0')
	{
		if(*str==c)
			count++;
		str++;
	}
	return count;
}
int main()
{

	int choice;
	char str[20];// A String of max 20 characters

	do{
	printf("\n0. Exit\n1.Accept String\n2.Display String\n3.Get length of string\n4.Copy string\n5.Equal strings?\n6.Reverse string\n7.Palindrome?\n8.Substring?\n9.Concatenate\n10. Compare 2 strings\n");//Menu
	scanf("%d",&choice);
	char str1[20];
	switch(choice)
	{
		case 1: accept(str);break;//Accept String

		case 2: display(str);break;//Display String

		case 3: printf("Length of %s=%d",str,length(str));break;//Length of String

		case 4:	copy(str,str1);//Copy string
			printf("\nCopied string=");
			display(str1);
			break;

		case 5:	printf("Enter two strings:");//Check if 2 strings are equal
			scanf("%s",str);
			scanf("%s",str1);
			printf("%s?=%s:%d",str,str1,equal(str,str1));
			break;

		case 6:	printf("Enter string to reverse:\n");//Reverse string
			accept(str);
			reverse(str,str1);
			printf("Reverse of %s=%s",str1,str);
			break;

		case 7: printf("Enter string to check palindrome:\n");//Check palindrome.
			accept(str);
			palindrome(str);
			break;

		case 8: printf("Enter 2 strings, whether 2nd is a substring of 1st\n");//Substring Checker, with overlap
			accept(str);
			accept(str1);

			if(match2(str,str1,1)>0){printf("%s is a substring of %s.",str1,str);
			printf("%s is present %d times in %s, considering overlaps also\n\n",str1,match2(str,str1,1),str);}

			else printf("%s is not a substring of %s.",str1,str);
			break;

		case 9:	printf("\nEnter 2 strings, to concatenate 2nd to 1st\n");//Concat 2 strings
		       	accept(str);
			accept(str1);
			concatenate(str,str1);
			printf("Concatenated string=%s\n",str);
			break;

		case 10:printf("Enter 2 strings to compare:");//Compare 2 strings
			accept(str);
			accept(str1);
			int d=compare(str,str1);
			if(d>0){printf("%s is greater than %s",str,str1);}
			if(d<0){printf("%s is less than %s",str,str1);}
			if(d==0){printf("%s is equal to %s",str,str1);}
			printf("\nResult=%d",d);
			break;


	}
	printf("\n------------------------------------------\n");

	}while(choice!=0);

	return 0;
}
