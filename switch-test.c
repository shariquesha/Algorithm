/*
Author Sharique

Test Wheather switch works on string in char
output:
Compile Error:

error: switch quantity not an integer
error: could not convert '"ABCCCDD"' from 'const char [8]' to '<type error>'

*/


#include<stdio.h>
int main()
{
char inchar[8] = "ABCCCDD";
switch (inchar)
{
case "ABCCCDD" :
	printf ("Works\n") ; break;
default:
	printf ("No Choice") ;
}

return 0;
}
