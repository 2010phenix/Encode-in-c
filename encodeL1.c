//  Program for encode any string
#include<stdio.h>
#define LIM 100						//    String's limit
#define DIFF 7                       //   replace every char with given difference ex. 'a' -> 'a' + DIFF = 'h'

void encode_L1(char *ptr,int len);  //  It is level one encoder that can encode string and file's conent till encoutered first blank space or new line ......

void main()
{
	char str[LIM];
	int len = 0;

	scanf("%s",str);             // for multiple space input use %[^\n] in place of %s
	
	while(str[len] != '\0')      // i think just for counting length of string i shold not use string library
		len++;
	
	encode_L1(str,len);       //  Calling level 1 encode function
	
	printf("%s",str);
}
/*
	If you don't want to encode special characters in while loop you can add 
	a conition for set string's range between a-z or A-Z
	but at every loop compiler have to check this so time will increse ..  (not too much)(in miliseconds)
*/	   
void encode_L1(char *ptr,int len)
{	
	while(len--)
	{
		if( ( ((*ptr)<='z') && ((*ptr)>='a') ) || ( ((*ptr)>='A') && ((*ptr)<='Z') ) )    // this condition
		{
			if( (  ((*ptr)<=('z'-DIFF)) && ((*ptr)>('a'-DIFF))  ) || (  ((*ptr)>('A'-DIFF)) && ((*ptr)<=('Z'-DIFF))  ) )
			{
				(*ptr) += DIFF;
			}
			else
			{
				(*ptr) += DIFF - 26; 	
			}
		}
		ptr++;
	}
}
