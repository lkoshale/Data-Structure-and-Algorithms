
/* 
Determine the common prime-factors of two positive integers.

Input Description: A single line containing two space-separated integers

Expected Output: A single line containing space-separated common prime factors of the
two integers

ex
Input: 36 54
Output: 2 3


*/

#include<stdio.h>

/* declaration for fn for checking prime*/
int Checkprime(int x);

int main()
{
	int num1,num2; 
	
	scanf("%d %d",&num1,&num2);		//scanning both numbers
	
	int i;						//counter variable
	int max;
	int flag;						//flag to store the no checkprime fn returns
	
	/* finding max*/
	if(num1>num2)
	{
		max=num1;
	}
	else
	{
		max=num2;
	}
	
	/* finding the common factors */
	for(i=2;i<=max;i++)
	{
		if( (num1%i==0)&&(num2%i==0) )
		{
			flag=Checkprime(i); 		// calls the fn to check	
			
			if(flag==1)
			{
				printf("%d ",i);		//printing the values
			} 	
									
		} //end if

	}	//end for
	
} 	// end main


/* checking given element is prime or not */
int Checkprime(int x)
{
	int i;
	
	if(x%2==0)
	{
		if(x==2)
		{
			return 1;  // 1 for prime as 2 is prime
		}
		else
		{
			return 0; 	// 0 for not prime 
		}
	}
	else
	{
		for(i=3;i<x;i++)
		{
			
			if(x==3)
			{
				return 1;	 // 1 for prime as 3 is prime
			}
			
			if(x%i==0)
			{
				return 0;
			}
			
		} // end for
		
		return 1;
		 
	} // end else

} 	//end fn
