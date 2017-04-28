/* 
Implement a function to calculate the square root of an integer precisely upto 15 digits
after decimal point (Note: You are not supposed to use any library function to calculate
the square root violating which will result in 0 for this question). 
You can assume that 1 =< n <= 104 where n is the input number

Input Description: A single line containing an integer

Expected Output: A single line containing a floating point number in the aforementioned
				format

ex

Input: 2
Output: 1.414213562373095

*/

#include<stdio.h>


/*decalring fn*/
double sqrt1( long int x);


int main()
{
	long int n;		//storing the input
	
	double y;		
	
	scanf("%ld",&n);	//input the number
	
	y= sqrt1(n);		//calling the fn
	
	printf("%0.15lf",y);		//printing the root upto 15 decimal places
	
	return 0;
	
} 		// end main



/* finding root by newtons method */
double sqrt1( long int x)
{
	double gues = 1; 	//initial guess for root
	
	
	int k,maxk=100; 	//variables and no of iteration
	
	
	/*aproxmimating the root by iteration*/
	for(k=0;k<maxk;k++)
	{
		gues = gues -( (gues*gues - x)/(2*gues) ) ;  	//newtons approximation
	
	}
	
	return gues;	//returning value
	
} //end fn
