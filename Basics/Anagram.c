
/* 
Given two strings of lowercase letters as input, determine if both are anagrams. Anagrams of a string are formed by 
permuting the characters in it and a set of characters can
form several anagrams. You can assume that 1 = n1, n2 = 100 where n1 and n2 are the
lengths of the two string respectively.

Input Description: A single line containing two space-separated strings

Output Description: A single line containing 1 if the strings are anagrams or 0 otherwise.

example

Input: programming mmioprrngag
Output: 1

Input: computer retmpucu
Output: 0

*/

#include<stdio.h>
#include<string.h> 		//including string library file

int main()
{
	/*declaring array of strings*/
	char str1[101];
	char str2[101];
	
	scanf("%s %s",&str1,&str2);   // scanning strings
	
	int i,j;					// counter variables
	int flag;					
	
	/*comparing the lengths of strings*/
	if(strlen(str1)!=strlen(str2))
	{
		printf("0");
	}
	else
	{
		for(i=0; str1[i]!='\0';i++)		// until the last char
		{
			flag=0;
		
			for(j=0; (str2[j]!='\0') ;j++)
			{
				if(str2[j]==str1[i])		// comparing each element of str1 to all element od str2
				{
					flag=1;
					break;
				}
			
			}
		
			if(flag==0)
			{
				break;
			}
		
		} // end for
		
		
		/* printing the output */
		if(flag==1)
		{
			printf("1");
		}
		else
		{	
			printf("0");
		}
	
	} 		//end else
	
	
		return 0;
		
}		// end main 
