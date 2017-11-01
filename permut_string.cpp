//Permutations of a string
#include<stdio.h>
#include<string.h>

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
permutation(char *s, int l , int r)
{
	int i;
	if(l == r)
	printf("%s\n",s);
	else
	{
		for(i = l ; i <= r; i++)
		{
			swap((s+l),(s+i));
			permutation(s,l+1,r);
			swap((s+i),(s+l));
			
		}
	}
}
int main()
{
	char s[] = "shar";
	int n = strlen(s);
	permutation(s,0,n-1);
	return 0;
}
