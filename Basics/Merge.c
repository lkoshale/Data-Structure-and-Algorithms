/*
Merge two sorted arrays without using additional space.

Input:
n, number of elements in first array
The n array elements
m, number of elements in the second array
The m array elements

Output:
Two merged arrays such that the initial numbers (after complete sorting) are in the first array and the
remaining numbers are in the second array (extra space allowed is O(1))


Example:
If the input array A1 is {1, 5, 9, 10, 15, 20} and A2 is {2, 3, 8, 13}, then the output should have A1 to be
{1, 2, 3, 5, 8, 9} and A2 to be {10, 13, 15, 20}. Print each array on a separate line, with each line containing
the elements separated by a single space.


*/

#include<stdio.h>

/*sorting method */
void isort(int* a,int*b,int m,int n);

int main()
{
	int n;	//no of elements of array1
	
	scanf("%d",&n);	//scanning n

	int a[n];		//array of n

	int i ,j;		//counter variables

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);	//input array elements array1
	}


	int m;		//no of elements arry2

	scanf("%d",&m);
	
	int b[m];	//array2

	for(j=0;j<m;j++)
	{
		scanf("%d",&b[j]); 	//scanning elements of array2
	}
	
	isort(a,b,n,m);		//calling fn
	

	/*printing the two arrays*/
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n");

	for(i=0;i<m;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");

}//end main


/* sorting fn*/
void isort(int* a,int* b,int m,int n)
{
	int i,j;	//counter variables

	for(i=n-1;i>=0;i--)	//starting from last element of 
	{
		int last = a[m-1];	//storing last element of arr1 in last
		int flg=0;		//flag variable

		for(j=m-1;j>=0 && a[j]>b[i];j--)	//comparing from the last element of array1
		{
			if(j!=m-1)
			{
				a[j+1]=a[j];	//moving the elemnt by one position forward
				flg =1;		//flag on
			}
		}

		if(j!=m-1 || flg==1)
		{
			a[j+1]=b[i];	//inserting the last n-1 elemnt of arry2 in arry1
			b[i]= last;	
		}
	}//end for

}//end fn

