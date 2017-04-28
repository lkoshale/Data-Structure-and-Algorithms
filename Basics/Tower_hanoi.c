/* 
	
Solve the Towers of Hanoi puzzle. There are three pegs, say A, B and C. The peg A has n disks (each of
different size) attached to it. The disks are arranged in decreasing order of size, with the smallest on top.
The objective is to move these disks to the peg C, while following the given rules:
• Only one disk can be moved at a time
• Only the topmost disk of a peg can be moved
• A moved disk can be placed only on the top of the disks on any peg
• No disk can be placed above a disk smaller than itself

Input Description: A singleline containing an integer,n, the number of disks at A before the game starts.

Expected output As many number of lines as the number of possible movements of disks between all pairs
of pegs until all of them are moved to C with each line containing output in the following format, followed
by a line containing the number of movements
"source_peg -> dest_peg disks_at_A disks_at_B disks_at_C"


Ex:
Input:
3
Output:
A -> C 2 0 1
A -> B 1 1 1
C -> B 1 2 0
A -> C 0 2 1
B -> A 1 1 1
B -> C 1 0 2
A -> C 0 0 3
7


	
*/

#include<stdio.h>

/*struct to store name and no of disk of peg*/
struct bar
{
	char name;
	int no;
};

/*recursive function */
void Hanoi(struct bar* init,struct bar* dest,struct bar* aux,int n,int* mov);

int main()
{
	int  n;			// no of disks given at starting
	
	scanf("%d",&n);		
	
	/*declaration of the pegs*/
	struct bar init;
	struct bar dest;
	struct bar aux;
	
	
	int *mov;			//pointer pointing to no of steps
	int steps=0;	//no of steps
	
	mov = &steps;		//assigning value to pointer
	
	
	/*initializing the pegs */
	init.name= 'A' ;
	dest.name = 'C' ;
	aux.name = 'B' ;
	
	init.no = n;
	dest.no = 0;
	aux.no = 0 ;
	
	/*calling the recursive fn*/
	Hanoi(&init,&dest,&aux,n,mov);
	
	printf("%d",steps);		//printing no of steps
	
	return 0;

}  //end main
	

/*recursive fn*/
void Hanoi(struct bar* init,struct bar* dest,struct bar* aux,int n,int*mov)
{
	if(n==1)		// base case
	{
		printf("%c -> %c  ",init->name,dest->name);
		
		(*mov)++ ;		//incrementing moves
		
		printf("%d %d %d \n",--init->no,aux->no,++dest->no);
		
	}
	else if(n==2)		// base case
	{
		/*step 1*/
		printf("%c -> %c ",init->name,aux->name);
		
		(*mov)++;		//incrementing moves
		
		/*printing the disks on peg A B C in order respectively*/
		if(init->name=='A'&&dest->name=='C'&&aux->name=='B')
		{
			printf("%d %d %d \n",--init->no,++aux->no,dest->no);
		}
		else if(init->name=='A'&&dest->name=='B'&&aux->name=='C')
		{
			printf("%d %d %d \n",--init->no,dest->no,++aux->no);
		}
		else if(init->name=='B'&&dest->name=='A'&&aux->name=='C')
		{
			printf("%d %d %d \n",dest->no,--init->no,++aux->no);	
		}
		else if(init->name=='B'&&dest->name=='C'&&aux->name=='A')
		{
			printf("%d %d %d \n",++aux->no,--init->no,dest->no);	
		}
		else  if(init->name=='C'&&dest->name=='A'&&aux->name=='B')
		{
			printf("%d %d %d \n",dest->no,++aux->no,--init->no);	
		}	
		else
		{
			printf("%d %d %d \n",++aux->no,dest->no,--init->no);	
		}
		
	
		/*next step*/
		printf("%c -> %c ",init->name,dest->name);	
		
		(*mov)++;		//incrementing moves
		
		/*printing the disks on peg A B C in order respectively*/		
		if(init->name=='A'&&dest->name=='C'&&aux->name=='B')
		{
			printf("%d %d %d \n",--init->no,aux->no,++dest->no);
		}
		else if(init->name=='A'&&dest->name=='B'&&aux->name=='C')
		{
			printf("%d %d %d \n",--init->no,++dest->no,aux->no);
		}
		else if(init->name=='B'&&dest->name=='A'&&aux->name=='C')
		{
			printf("%d %d %d \n",++dest->no,--init->no,aux->no);	
		}
		else if(init->name=='B'&&dest->name=='C'&&aux->name=='A')
		{
			printf("%d %d %d \n",aux->no,--init->no,++dest->no);	
		}
		else  if(init->name=='C'&&dest->name=='A'&&aux->name=='B')
		{
			printf("%d %d %d \n",++dest->no,aux->no,--init->no);	
		}	
		else
		{
			printf("%d %d %d \n",aux->no,++dest->no,--init->no);	
		}
		
		
		/*next step*/
		printf("%c -> %c ",aux->name,dest->name);
		
		(*mov)++;		//incrementing moves
		
		/*printing the disks on peg A B C in order respectively*/
		if(init->name=='A'&&dest->name=='C'&&aux->name=='B')
		{
			printf("%d %d %d \n",init->no,--aux->no,++dest->no);
		}
		else if(init->name=='A'&&dest->name=='B'&&aux->name=='C')
		{
			printf("%d %d %d \n",init->no,++dest->no,--aux->no);
		}
		else if(init->name=='B'&&dest->name=='A'&&aux->name=='C')
		{
			printf("%d %d %d \n",++dest->no,init->no,--aux->no);	
		}
		else if(init->name=='B'&&dest->name=='C'&&aux->name=='A')
		{
			printf("%d %d %d \n",--aux->no,init->no,++dest->no);	
		}
		else  if(init->name=='C'&&dest->name=='A'&&aux->name=='B')
		{
			printf("%d %d %d \n",++dest->no,--aux->no,init->no);	
		}	
		else
		{
			printf("%d %d %d \n",--aux->no,++dest->no,init->no);	
		}
		
	}
	else			//for n>2
	{
		int x = n-1;	
		
		/*recursive calling the fn*/
		Hanoi(init,aux,dest,x,mov);
		
		printf("%c -> %c ",init->name,dest->name);
		
		(*mov)++; 		//incrementing moves
		
		/*printing the disks on peg A B C in order respectively*/		
		if(init->name=='A'&&dest->name=='C'&&aux->name=='B')
		{
			printf("%d %d %d \n",--init->no,aux->no,++dest->no);
		}
		else if(init->name=='A'&&dest->name=='B'&&aux->name=='C')
		{
			printf("%d %d %d \n",--init->no,++dest->no,aux->no);
		}
		else if(init->name=='B'&&dest->name=='A'&&aux->name=='C')
		{
			printf("%d %d %d \n",++dest->no,--init->no,aux->no);	
		}
		else if(init->name=='B'&&dest->name=='C'&&aux->name=='A')
		{
			printf("%d %d %d \n",aux->no,--init->no,++dest->no);	
		}
		else  if(init->name=='C'&&dest->name=='A'&&aux->name=='B')
		{
			printf("%d %d %d \n",++dest->no,aux->no,--init->no);	
		}	
		else
		{
			printf("%d %d %d \n",aux->no,++dest->no,--init->no);	
		}
			
		/*recursive calling the fn*/
		Hanoi(aux,dest,init,x,mov);
		
	}	//end else
	
}	//end fn
