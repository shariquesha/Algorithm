//Edit Distance dp solution

#include<iostream>
#include<cstring>

using namespace std;

int MIN(int a,int b)
{
	return ((a>b)?b:a);
}

int min(int a,int b, int c)
{
	return MIN(a,MIN(b,c));
}
int EditCost(char *str1,char *str2)
{
	int n = strlen(str1);
	int m = strlen(str2);
	
	int tab[n+1][m+1];
	int i,j;
	
	for(i = 0; i <= n ; i++) tab[i][0] = i;
	for(i = 0; i <= m ; i++) tab[0][i] = i;
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m ; j++)
		{
			if(str1[i-1] == str2[j-1] )
			{
				tab[i][j] =  tab[i-1][j-1];
			}
			else
			tab[i][j] = 1 + min(tab[i-1][j-1],tab[i-1][j],tab[i][j-1]);
		}
	}
	return tab[n][m];
}
int main()
{
	char *s1 = "aa";
	char *s2 = "aaaa";
	cout<<EditCost(s1,s2)<<endl;
}
