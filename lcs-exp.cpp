//lcs exponential solution
#include<iostream>
#include<cstring>
using namespace std;

/*int max(int a,int b)
{
	return ((a > b) ? a : b);
}*/

void retLcs(char *str1,int start,char *str2,int n,int m,int *lcs)
{
	if(start == n) return;
	int count = 0,i = start,j= 0,s= 0;
	while(i != n)
	{
		if(str1[i] == str2[j])
		{
				i++; j++; count++; s = j;
		}
		else
		{
				j = s;
				
				while(j != m && str1[i] != str2[j])
					j++;
					
				if(j == m)
					i++;
				
		}
	}
	if(count > *lcs)
	*lcs = count;
	retLcs(str1,start+1,str2,6,7,lcs);
}

int main()
{
	char *str1 = "AAGTAB";
	char *str2 = "GXTXAYB";
	int lcs = 0;
	retLcs(str1,0,str2,6,7,&lcs);
	cout<<lcs<<endl;
}
