#include<iostream>
#define MAX 1000
using namespace std;

int dp[4][4];

int MIN(int a,int b)
{
	return ((a>b)?b:a);
}
int min(int a,int b, int c)
{
	return MIN(a,MIN(b,c));
}
int BuildTable(int mat[3][3]){
	int i,j;
	
	
	for(i = 0 ; i <= 3 ; i++)
	{
		dp[3][i] = MAX;
		dp[i][3] = MAX;
	}
	for(i = 2  ; i >= 0 ; i--)
	{
		for(j= 2  ; j >=  0 ; j--)
		{
				if(i==2 && j==2) dp[i][j]= mat[i][j];
				else
				dp[i][j]= mat[i][j] + min(dp[i][j+1],dp[i+1][j+1],dp[i+1][j]);
		}
	}
}
int minCost(int x,int y)
{
	return dp[x][y];
}
int main()
{
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    BuildTable(cost);
   cout<<minCost(0,0)<<endl;
   cout<<minCost(1,0)<<endl;
   cout<<minCost(2,0)<<endl;
   cout<<minCost(0,2)<<endl;
   cout<<minCost(1,2)<<endl;
   cout<<minCost(2,2)<<endl;
   return 0;
}
