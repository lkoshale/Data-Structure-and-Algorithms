/* 

Calculate the determinant of a given square matrix of integers.

Input Description: First line of the input will contain a single integer N, followed by N lines,the rows of
the matrix, each containing N integers. Note: You can assume that 1 = N = 10 and elements of the matrix
will fit into 32-bit signed integer whereas determinants will fit into 64-bit signed integer.

Expected Output: A single line containing an integer, i.e. the determinant of the matrix

example:

Input:
4
1 2 3 4
3 4 5 -1
6 0 -2 4
-9 1 7 3

Output:
212

*/


#include<stdio.h>
#include<math.h>


/*struct to store the two dimension matrix*/
struct mat
{

	int matrix[10][10];

}; //end struct


/*function to detrmine the cofacor of the matrix element  i , j*/
struct mat cofactorM(struct mat M,int i,int j,int order);


/*recursive function to find determinant */
long int det(struct mat M ,int order);



int main()
{
	int order;		//size or order of the input matrix
	
	scanf("%d",&order);		//scanning order
	
	int i,j;				//counter variables
	
	long int determinant;		//for storing the determinant

	struct mat givenM ;			//declaring struct of type mat to store matrix
		
		
	/*input the elements of the 2d array*/
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			scanf("%d",&givenM.matrix[i][j]);
		}
		
	} 	//end for
	
	
	
	determinant = det(givenM,order);		//calling the recursive fn
	
	printf("%ld",determinant);				// printing the value
	
	return 0;
	
}	//end main


/*function to find the cofactor matrix of element i,j */
struct mat cofactorM(struct mat M,int i,int j,int order)
{
	struct mat temp;	//to store the cofactpr array
	
	int x=0,y=0;	// 
	
	int row,col;	//counter varibles
	
	/*finding the cofactor matrix*/
	for( row=0;row<order;row++)
	{
		for( col=0;col<order;col++)
		{
			if( (row!=i)&&(col!=j) )
			{
				temp.matrix[x][y] = M.matrix[row][col] ;	//assigning values in temp
				
				y++;	//incrementing the column of temp matrix to store next element
				
				if(y == order-1)	//if reach end of parent matrix
				{
					y=0;		//reseting column to 0 of temp
					
					x++;		//incrementing the row of temp
					
				} 	//end inner if
				
			}	//end outer if
			
		}	// end inner for
		
	}	//end outer for
	
	
	return temp;
	
	
}	// end fn



/*recursive fn to determine the determinant*/
long int det(struct mat M,int order)
{
	
	int row,col;	//counter variables
	
	long int ans=0;		
	
	struct mat temp;	// to store the cofactor matrix of the element
	
	if(order==1)
	{
		return M.matrix[0][0];	//base case
	}
	else if(order==2)
	{
		return ( ( M.matrix[0][0]*M.matrix[1][1] ) - (M.matrix[0][1]*M.matrix[1][0] ) ); 	//base condition
	}
	else 
	{
		/*order greater than 2*/
		for(row=0,col=0;col<order;col++)	
		{
			/*finding cofactor*/
			temp = cofactorM(M,row,col,order);
		
			/*finding the determinant recursively */
			ans= ans + pow( -1, row+col)*M.matrix[row][col]*( det(temp,order-1) ) ; 
		
		}	//end for
		
		
	} 	//end else
	
	return ans;		//returning value
	
}//end fn
