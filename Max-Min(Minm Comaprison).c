/* 

Implement a function to find the Maximum and the Minimum of an array of integers
using minimum number of comparisons. You can assume that 1 = n = 100 where n is the
size of the array

Input Description:
 First line of the input will have a single integer n, the size of the
array, followed by n space-separated integers, the array elements, in the second line.

Output Description: 
Single line containing two space-separated integers, namely, Minimum and the Maximum of the array

ex

Input:
5
2 1 3 5 8

Output: 1 8

*/

#include<stdio.h>

/*define struct*/
struct pair 
{
	int max;
	int min;
};


struct pair MaxMin(int* a,int sindex,int eindex); // function declaration

int main()
{
	int n; // no of elements in array
	
	struct pair out; // define variable for output
	
	scanf("%d",&n); //scanning n

	/* declaring variables and arrays*/
	
	int arr[n];
	int startindex=0;
	int endindex=n-1;
	
	int i; //counter

	for(i=0;i<n;i++) // scanning elements of array
	{
		scanf("%d",&arr[i]);
	}
	
	out= MaxMin(arr,startindex,endindex); //calling the function 
	
	printf("%d %d \n",out.max,out.min);

	return 0;

} //end main



/* recursive function to find max and min  */

struct pair MaxMin(int* a,int sindex,int eindex)
{
	struct pair temp;

	/*defining variable*/
	int left=sindex,right=eindex; 
	int mid;

	/*for recursion*/
	struct pair divideR,divideL; 

	mid=(right-left)/2 ; // mid for dividing array
	

	if(right==left) // only 1 element
	{
		temp.max=a[left];
		temp.min=a[left];
	}
	else if(right==left+1) //only two element
	{
		if(a[left]>a[left+1])
		{
			temp.max=a[left];
			temp.min=a[right];
		}
		else
		{
			temp.max=a[right];
			temp.min=a[left];
		}
	
	}
	else // more than 2 elements 
	{

		/*recursively calling function while dividing in two halves */
		divideL = MaxMin(a, left, mid); 
		divideR = MaxMin(a, mid+1, right);

		/* comparing the max and min of two halves */
		if(divideL.max>divideR.max)
		{	
			temp.max=divideL.max;
		}
		else
		{
			temp.max= divideR.max;
		}

		if(divideL.min<divideR.min)
		{	
			temp.min=divideL.min;
		}
		else
		{
			temp.min= divideR.min;
		} //end else

	} //end else

	return temp;
}

