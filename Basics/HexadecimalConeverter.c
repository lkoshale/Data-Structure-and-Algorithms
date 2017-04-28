/*
Given an integer as input, convert it to its Hexadecimal equivalent. You can assume
that 1 <= n <= 109 where n is the given decimal number

Input Description: A single line containing an integer

Expected Output: a single line containing the Hexadecimal equivalent of the input integer

exInput: 1562
Output: 0x0000061a

*/

#include<stdio.h>


/* main program */
int main()
{
	long long unsigned int n;  // integer for storing large values
	
	scanf("%llu",&n);  //scanning n
	
	int i,j,k;  // counter variables
	
	int r[8];   //array for storing the reminders
	
	
	/* initializing array*/	
	for(j=0;j<8;j++)
	{
		r[j]=0;
	}
	
	
	/* evaluating the reminders */
	for(i=0;n!=0;i++)
	{
		r[i]=n%16;
		n=n/16;
		
		/* switching r[i] for values greater than 10 and 
		storing as the integer value for character typ in c*/
		switch(r[i])  
		{
			case 10:
					r[i] = 97;  //int value of a
					break;	
			case 11:
					r[i] = 98;  //int value of b
					break;
			case 12:
					r[i] = 99;		//int value of c
					break;	
			case 13:
					r[i] = 100;		//int value of d
					break;	
			case 14:
					r[i] = 101;		//int value of e
					break;				
			case 15:
					r[i] = 102;		//int value of f
					break;			
		
		}	//end switch
		
	} //end for
	
	printf("0x");  //printing the prefix 
	
	
	/* printing the hexadecimal value*/
	for(k=7;k>=0;k--)
	{
		if( r[k] < 10 )
		{
			printf("%d",r[k]);
		}
		else
		{
			printf("%c",r[k]);
		}
	}
	
	return 0;
	
}	//end main
