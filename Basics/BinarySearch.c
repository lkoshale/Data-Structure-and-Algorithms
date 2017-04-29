/*
Implement Binary Search in the following three ways, where the array is partitioned as:
1. 1/2 and 1/2
2. 1/3 and 2/3
3. Three parts of 1/3 size each

Input:
n, the number of elements in the array
The n array elements
k, the key to be searched

Output:
The position (array index) of the key in the array, if the key is present; or print -1 to indicate the key is
absent in the array
The number of comparisons to be made for each of these three cases, comma separated


*/

#include<stdio.h>

// sruct to store answer
struct ans
{
	int index;
	int count;
};


//three fn for each procedure
struct ans binary1(int a[],int start,int size,int k);

struct ans binary2(int a[],int k,int start,int end);

struct ans binary3(int a[],int k,int start,int end);


int main()
{
	int n;	//no of elements
	
	scanf("%d",&n);		

	int array[n];	//array of size n

	int i , j;	//counter variables

	//input the array elements
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	//key
	int k;

	scanf("%d",&k);	

	//for storing the index and count
	struct ans bhalf,b2third,b1third;

	//calling all the three fn
	bhalf = binary1(array,0,n,k);

	b2third = binary2(array,k,0,n);

	b1third = binary3(array,k,0,n);

	//printing values
	printf("%d %d %d\n",bhalf.index,b2third.index,b1third.index);

	printf("%d %d %d\n",bhalf.count,b2third.count,b1third.count);

	
	return 0;

}//end main


//binary function
struct ans binary1(int a[],int start,int size,int k)
{
	//variable declaration
	int middle;		
	int left=start,right=size-1;
	int i ,j;

	struct ans A1;

	A1.index = -1;
	A1.count = 0;

	
	//searching the element while dividing into half parts
	while(left<=right)
	{

		middle = (right+left)/2;

		if(k==a[middle])
		{
			A1.index = middle;
			A1.count++;
			break;	
		}
		else if(k>a[middle])
		{
			left = middle+1;
			A1.count++;
		}
		else 
		{
			right = middle-1;
			A1.count++;
		}

	}
	
	return A1;

}//end binary1 fn


//fo dividing array into two three halves
struct ans binary3(int a[],int k,int start,int end)
{

	struct ans A1;

	A1.index = -1;
	A1.count = 0;

	
	//dividng into two three halves and searching
	while(start<end)
	{
	
		int mdl1 = start + (end-start)/3 ;

		int mdl2 = start + 2*(end-start)/3;

		if(k==a[mdl1])
		{
			A1.index = mdl1;
			A1.count++;
			break;	
		}
		else if(a[mdl2]==k)
		{
			A1.index = mdl2;
			A1.count++;
			break;	

		}
		else if(k<a[mdl1])
		{
			A1.count++;
			return binary3(a,k,start,mdl1-1); 		
		}
		else if(k>a[mdl2])
		{
			A1.count++;
			return binary3(a,k,mdl2+1,end);
		}
		else
		{
			A1.count++;
			return binary3(a,k,mdl1,mdl2);
			
		}

	}

	return A1;	
}//end fn


//dividing array into parts n/3 and 2n/3
struct ans binary2(int a[],int k,int start,int end)
{

	struct ans A2;
	
	A2.index= -1;
	A2.count= 0;

	//dividing and searching
	while(start<end)
	{

		int p1 = start + (end-start)/3;
				

		if( k==a[p1] )
		{
			A2.index = p1;
			A2.count++;
			break;
		}
		else if( k< a[p1] )
		{
			A2.count++;
			return binary2(a,k,start,p1-1);

		}
		else
		{
			A2.count++;
			return binary2(a,k,p1,end);	
		}
		
	}

	return A2;
	
}//end fn


