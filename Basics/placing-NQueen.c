/* 

Solve the N-Queens problem. You are expected to place N queens on an N × N chess board such that none
of the queens can attack the others i.e. they do not share the same row, column or diagonal.

Assume the chess board to be a grid with rows and columns both going from 0 to N - 1. The position of
each cell is thus represented by (i; j) where i; j 2 [0; N - 1].

To make things clear, suppose the size of the chess-board/grid is 5 × 5, then possible attacking and nonattacking position from cell (1,2) are shown below, where positions marked by asterisk(*) can be attacked
by queen at (1,2) and those with 0 can’t be:

0 * * * 0
* * 1 * *
0 * * * 0
* 0 * 0 *
0 0 * 0 0

input Description: A single line containing an integer, N, the size of the grid and the number of queens.
You can assume that 1 = N = 12

Expected output: As many lines as the number of possible non-attacking configurations with each line
containing N integers where ith integer represents the non-attacking cell of the ith row followed by a line
containing single integer representing the number of such configurations.

Ex: for N=4, there are only two possible configurations to place queens in non-attacking positions, which
are following-
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
Cells containing 1s correspond to the positions of the queens
Note: Refer to this example to understand the output format, as described above, for the sample input
assuming 0-based indexing.

Input:
4

Output:
1 3 0 2
2 0 3 1
2

*/

#include<stdio.h>
#include<math.h>


/*recursive fn to find the places in n*n board */
void N_queen(int row,int n);

/*to print values*/
void print(int n);

/*check if queen can be placed*/
int can_be_placed(int row,int column);


/*array to store the jth column where index i is the ith row  */
int board[25];		

int count;		// varible to count the no of solutions
 
 
int main()
{
	int n;		//no of queens or n of nxn board
	 
 	scanf("%d",&n);		//scanning the n
 	
 	/*calling recursive fn*/
	N_queen(1,n);
 
 	printf("\n%d",count);		//printing the no of solutions
 
 	return 0;

}
 
//function for printing the index of column for each row
void print(int n)
{
 	int i,j;		//counter varibles
 
 	++count;		//incrementing count
 	
	printf("\n");	//new line
 
 	/*printing the jth column of n*n board */
	for(i=1;i<=n;++i)
 	{
		for(j=1;j<=n;++j) 
  		{
 			if(board[i]==j)		//if the queen is placed
   			{
   				printf("%d  ",j-1);		//print the column index
   			}
  
  		}	//end inner for
 	
	}	//end outer for	

}	//end fn
 
 
 
/*funtion to check if queen can be placed means no conflict or not 1 if can be placed or 0 otherwise*/
int can_be_placed(int row,int column)
{
	int i;
 	
	 
	for(i=1;i<=row-1;++i)
 	{
  		//checking column  conflicts
  		if(board[i]==column)
   		{
			return 0;
		}
  		else
  		{  
			if(abs(board[i]-column)==abs(i-row))		//checking daigonal conflicts
    		return 0;
 		}
 
 	}
 
 	return 1; //no conflicts

} //end fn


 
//function to position the queen if no conflicts
void N_queen(int row,int n)
{
	int column;
 	
	for(column=1;column<=n;++column)
 	{
  		
		if( can_be_placed(row,column) == 1 )
		{
   		
		   	board[row]=column; //no conflicts so place queen
   		
		   	if(row==n) 		//no more rows
   			{
				print(n);	 //printing the values
   			}
		   	else 		//try queen with next position
    		{
				N_queen(row+1,n);
			
			}	//end else  
		
		} //end if		
 	
	} 	//end for

}	//end fn
