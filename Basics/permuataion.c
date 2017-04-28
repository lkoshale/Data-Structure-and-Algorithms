
/*

Implement permutations of a set of integers.

Input:
n(= 9), the number of integers

The integers, each in a separate line (Assume the integers are no more than 3 digits in size)

Output:
Every possible permutation of the n integers (n! in number)

Example 

input:
3 1 4 9

Output:
149 194 419 491 914 941

*/

#include<stdio.h>

/*declaring functions to swao the two elemnts with index i and j*/
void swap(int arr[],int x,int y);

/* declaration of the recursive fn to find permutations*/
void permutation(int arr[],int size,int i);



int main()
{
	
	int n;		//no of inputs
	int i;		//counter variable

	scanf("%d",&n);		//scanning n

	int arr[n];		// array to store the no.

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);		// sacnning and storing the no
	}

	permutation(arr,n,0); 		// calling the recursive fn

}	//end main


/*fn to swap the elments at i and j*/
void swap(int arr[],int x,int y)
{
	int temp; 	//temporary variable

	/*swaping the elements*/	
	temp= arr[x];
	arr[x]=arr[y];
	arr[y]= temp;

}	// end fn



/*recursive fn to find the permutations*/
void permutation(int arr[],int n,int i)
{
	int j; 		//counter variable
	
	/*if we are at end of array we have only one permutation*/

	if(i==n) 		// base case
	{
		for(j=0;j<n;j++)
		{
			printf("%d",arr[j]); 	//printing the elements
		}	

		printf("\n");
	}
	else 	//recursively calling fn to find the permutations
	{
		for(j=i;j<n;j++)
		{
			/* do with the array as i and j swaped */
			swap(arr,i,j);
			
			permutation(arr,n,i+1);		//recursively calling fn
			
			/*swap back to the i and j*/
			swap(arr,i,j);

		} 	// end for
	
	}	// end else

} //end fn

