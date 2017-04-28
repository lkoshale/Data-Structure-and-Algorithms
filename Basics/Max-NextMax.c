
/* 
Write a program to find the Maximum and the Next-Maximum of an array of integers.
Input Description: First line of the input will contain a single integer n, the size of
the array, followed by n space-separated integers, the array elements, in the second line. You
can assume that 2 <= n <= 105
Expected Output: A single line containing two space-separated integers with the
 				Maximum followed by the Next-Maximum in a single line
ex
Input:
10
2 9 8 1 3 -6 -18 19 15 -89
Output:
19 15

*/

#include<stdio.h>


/*for storing max and next max no */
struct pair
{
	int max;
	int nextmax;
};


/* declaration of fn for finding max */
struct pair FindMax(int*a,long int size);


int main()
{
	long int n;
	
	struct pair out;	//for output
	
	scanf("%ld",&n);	//scanning n
	
	int arr[n]; 		// array of n elements
	long int i;
	
	/*scanning array elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	out= FindMax(arr,n); 	//calling fn
	
	printf("%d %d",out.max,out.nextmax);	
	
} // end main



/* function for finding max and next max*/

struct pair FindMax(int*a,long int size)
{
	long int i,j,k;
	int flag=0;		//for storing index of maximum no.
	
	struct pair temp;	
	
	temp.max=a[0]; 		//intilaizing the temp variable to element 0
	temp.nextmax=a[0];
	
	/*loop for assign next max to minimum value in array*/
	for(k=1;k<size;k++)
	{
		if(a[k]<temp.nextmax)
		{
			temp.nextmax=a[k];
		
		}
	}
	
	/* loop for finding max element*/
	for(i=1;i<size;i++)
	{
		if(a[i]>=temp.max)
		{
			temp.max=a[i];
			flag=i;
		}
	}
	
	/*loop for finding next max*/
	for(j=0;j<size;j++)
	{
		if(j==flag)
		{
			continue; 	//escaping the max index
		}
		
		if(a[j]>temp.nextmax)
		{
			temp.nextmax=a[j];
		}
		
	}
	return temp;

} //end fn

 
