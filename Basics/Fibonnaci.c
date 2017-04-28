/* 
Implement the Fibonacci Sequence both iteratively and recursively. Create separate functions for finding the
nth Fibonacci number by iteration and recursion. Also calculate the time taken in each, and plot a graph.

Note: Assume F1 = F2 = 1.

Input:
n, the number of starting elements of the Fibonacci sequence to be printed

Output:
The first n elements of the sequence, space separated. The iterative and recursive versions should both be
printed on a separate line.


Calculate the time taken by each function for values 1 : : : 20. You will have to use the library "time.h" for
this. Here’s a handy primer.

Print the time taken for the iterative and recursive cases in a separate file titled "output.csv". This file
should contain 20 lines, each containing the time for iterative and recursive executions for that particular
number, separated only by a single comma. A line in this file is expected to look like this:
0.000001,0.000002

*/


#include<stdio.h>
#include<sys/time.h>

/*function declaration for recursive way*/
int FibRec(int x);

/*fn declaration for iterarive way */
int FibIter(int y);


int main()
{
	int n;		//variable for input no.

	scanf("%d",&n);			//scanning the number	

	
	int i,j,x;	// counter variables

	FILE *fptr;	// a file pointer 

	fptr = fopen("output.csv","a");		//open and create a output.csv in append mode


	/*for evaluating time*/	

	for(x=1;x<=20;x++)
	{
	

		struct timeval tBefore, tAfter;		//decalring the struct variables defined in time.h

		 long double timetaken,timetaken1;	// for storing the time of execution		
	

		/*measuring the time of execution of iterative way */
		gettimeofday (&tBefore, NULL);	 

		for(i=1;i<=x;i++)
		{
			int a;		
			a = FibIter(i);
		}
	
		gettimeofday (&tAfter, NULL);

		timetaken = ( long double)(  ( (tAfter.tv_sec - tBefore.tv_sec) *1000000L + tAfter.tv_usec ) - tBefore.tv_usec );	
	
	
		/* execution time for recursive way*/
		struct timeval tBefore1, tAfter1;

		gettimeofday (&tBefore1, NULL);	

		for(j=1;j<=x;j++)
		{
			int b;		
			b = FibRec(j);
		}
		
		gettimeofday (&tAfter1, NULL);
	
		timetaken1 = (long double)(  ( (tAfter1.tv_sec - tBefore1.tv_sec) *1000000L + tAfter1.tv_usec ) - tBefore1.tv_usec );
	
	
		fprintf(fptr,"%llf,%llf \n",timetaken,timetaken1); 	// writing the time taken by 
		
	
	}
	
	fclose(fptr);


	/*printing the values itertative fn*/

	for(i=1;i<=n;i++)
	{
		int a;		
		
		a = FibIter(i);

		printf("%d ",a);
	
	}

	printf("\n");	//new line


	/*printing the values for recursive way*/
	for(j=1;j<=n;j++)
	{
		int b;		
		
		b = FibRec(j);

		printf("%d ",b);
	}

	printf("\n");		//new line
	
	

}	//end main


/*fn for recursive way*/
int FibRec(int x)
{

	if( (x==1)||(x==2) )
	{
		return 1;		//base case
	}
	else
	{
		return FibRec(x-1)+FibRec(x-2);
	}	

}

/*fn for iteration */
int FibIter(int y)
{
	

	int i;		//counter variable
	
	if(y<=2)
	{
		return 1;
	}

	int first=1,second=1, next;  		//declaring variables

	for(i=0;i<y-2;i++)
	{
		next = first + second ;
		first = second;
		second= next;		
		
	}
	
	return second;

} // end fn

