//nCr - dp
#include<iostream>
#include<cmath>

#define ll long long int
using namespace std;

ll nCr(int n,int r)
{
	if(n < r) return 0;
	ll dp[n+1][r+1];
	
	for(int i = 1; i <= n ; i++)
	dp[0][i] = i;
	
	for(int i= 1; i <= n ; i++)
	{
		for(int j = 1; j <= r ; j++)
		{
			if(i == j) dp[i][j] =1;
			else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			
		}
	}
	
	return dp[n][r];
}
int main()
{
	int t,n,r;
	cin>>t;
	ll mod = pow (10,9) + 7;
	while(t--)
	{
		cin>>n>>r;
		cout<<nCr(n,r) % mod<<endl;
	}
	
	return 0;
}
