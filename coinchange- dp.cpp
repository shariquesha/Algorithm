//coin change dp approach
#include<iostream>
#include<cmath>
using namespace std;

int coinChange(int arr[],int n,int N)
{
	int tab[n+1][N+1];
	int i,j;
	
	for(i = 0; i <= N ; i++)
	{
		tab[0][i] = 0;
	}
	for(i = 0; i <= n ; i++)
	{
		tab[i][0] = 1;
	}
	
	for(i = 1 ; i <= n ; i++)
	{
		for(j = 1 ; j <= N ; j++)
		{
			if(arr[i-1] > j)
			tab[i][j] = tab[i-1][j];
			else
			tab[i][j] = tab[i-1][j] + tab[i][j - arr[i-1]];
		}
	}
	
	for(i = 0 ; i <= n ; i++)
	{
		for( j = 0 ; j <= N ; j++)
		{
			cout<<tab[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return tab[n][N];
}

int main()
{
	int arr[]= {1,2,5};
	cout<<coinChange(arr,3,11)<<endl;
	return 0;
}
