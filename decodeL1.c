//  Program for decode encoded string
#include<stdio.h>
#define LIM 100
#define DIFF 7

void decode_L1(char *ptr,int len);  //  It is level one decoder that can decode string and file's conent till encoutered first blank space or new line ......

void main()
{
	char str[LIM];
	int len = 0;
	
	scanf("%s",str);
	
	while(str[len] != '\0') 
		len++;
	
	decode_L1(str,len);       //  Calling level 1 decode function
	
	printf("%s\n",str);
}

void decode_L1(char *ptr,int len)
{	
	while(len--)
	{
		if( ( ((*ptr)<='z') && ((*ptr)>='a') ) || ( ((*ptr)>='A') && ((*ptr)<='Z') ) )    //  if i do not want to decode special charecters (because i havn't encoded it)
		{
			if( (  ((*ptr)<=('z')) && ((*ptr)>('g'))  ) || (  ((*ptr)>('G')) && ((*ptr)<=('Z'))  ) )
			{
				(*ptr) -= DIFF;
			}
			else
			{
				(*ptr) += 26 - DIFF ; 	
			}
		}
		ptr++;
	}
}

