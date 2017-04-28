
/* 

 Implement Abstract Data Type(ADT) Complex Number and associated operations
on them.
Hint: To represent a complex number (p + q.i) where p,q 2 R, define a structure with two
floating-point fields for real and imaginary parts respectively.

Implement following operations on complex numbers.
(a) Addition of two Complex Numbers
(b) Subtraction of two Complex Numbers
(c) Multiplication of two Complex Numbers
(d) division of two Complex Numbers
(e) Modulus/Magnitude/Absolute value of a Complex Number


Note: Write separate functions for each operation. Function corresponding to Modulus operation must return a floating point value precise upto 6 digits after decimal and functions
corresponding to rest of the operations must return a Complex Number. 
Upon execution,your program must present the user with an options-menu with option numbers (starting from 1) for each of the operations and a 
sentinel-value (-1 or 0) to terminate the program.Your program must prompt the user to enter two complex numbers, 
one in each line, followed by the choice of operation and repeat this until user decides to terminate the program.

ex:
Addition: 1
Subtraction: 2
Multiplication: 3
Division: 4
Modulus: 5

Input:
0 1
2 3
1

Output: 2 + 4i


*/

#include<stdio.h>
#include<math.h>

/* defining structure to store the
   complex nubers */
 
struct complex
{
	float real;
	float imag;
};

/* declaration of functions */

struct complex add( struct complex x, struct complex y);
struct complex subtraction( struct complex x, struct complex y);
struct complex multiplication( struct complex x, struct complex y);
struct complex division( struct complex x, struct complex y);
float modulus( struct complex x, struct complex y);


int main()
{
	/*declaring the variables */
	struct complex number1;
	struct complex number2;
	struct complex output;
	int i;
	float mod;

	scanf("%f %f",&number1.real,&number1.imag); //input num1
	scanf("%f %f",&number2.real,&number2.imag); //input num2
	
	/* looping the process with do while */
	do
	{
		scanf("%d",&i);
		
		if(i==1) //condition for addition
		{
			output= add(number1,number2); 
			
			if(output.imag<0) 
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}
		}
		else if(i==2) //condition for Subtraction 
		{
			output= subtraction(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}
		}
		else if(i==3) //condition for  multiplication
		{
			output= multiplication(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}

		}
		else if(i==4) //condition for  division
		{
			output= division(number1,number2);
			
			if(output.imag<0)
			{
				printf("%f %fi",output.real,output.imag);
			}
			else
			{
				printf("%f + %fi",output.real,output.imag);
			}

		}
		else if(i==5) //condition for  modulus (distance bw the points)
		{
			mod= modulus(number1,number2);
			
			printf("%0.6f",mod);	
		}
		else
		{
			break;
		}

	}while(i!= 0); //end while

	return 0;
}

/* addition of complex numbers */
struct complex add( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real+ y.real;
	temp.imag= x.imag+ y.imag;
	
	return temp;
}

/* subtraction of complex numbers */
struct complex subtraction( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real- y.real;
	temp.imag= x.imag- y.imag;
	
	return temp;
}

/* multiplication of complex numbers */
struct complex multiplication( struct complex x, struct complex y)
{
	struct complex temp;

	temp.real= x.real*y.real - x.imag*y.imag;
	temp.imag= x.real*y.imag + x.imag*y.real;
	
	return temp;
}

/* division of complex numbers */
struct complex division( struct complex x, struct complex y)
{
	struct complex temp;
	struct complex conjugate;
	struct complex y1;
	struct complex y2;

	conjugate.real= y.real;
	conjugate.imag= y.imag;

	y1= multiplication(x,conjugate);
	y2= multiplication(y,conjugate);

	if(y2.real==0)
	{
		printf("error divided by zero");

	}
	else
	{
	temp.real= y1.real / y2.real;
	temp.imag= y1.imag / y2.real;

	}
	
	return temp;
	
}

/* distance bw  complex numbers */
float modulus( struct complex x, struct complex y)
{
	float temp;

	temp= sqrt( (x.real-y.real)*(x.real-y.real) + (x.imag-y.imag)*(x.imag-y.imag) ); 
	
	return temp;
}

