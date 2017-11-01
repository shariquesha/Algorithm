//lcs - dp solution

#include<iostream>
#include<cstring>

using namespace std;

int max(int a, int b)
{
	return (a > b)?a:b;
}
int retLcs(char *str1,char *str2)
{
	int n = strlen(str1);
	int m = strlen(str2);
	
	int tab[n+1][m+1];
	int i ,j;
	
	for(i = 0; i <= n ; i++)
	{
		for(j = 0; j <= m ; j++)
		{
			if( i == 0 || j == 0)
			tab[i][j] = 0;
			
			else if(str1[i] == str2[j])
			{
				tab[i][j] = 1 + tab[i-1][j-1];
			}
			else
			{
				tab[i][j] = max(tab[i-1][j],tab[i][j-1]);
			}
		}
	}
	return tab[n][m];
}
int main()
{
	char *str1 = "ABCDGH";
	char *str2 = "AEDFHR";
	cout<<retLcs(str1,str2)<<endl;
}
