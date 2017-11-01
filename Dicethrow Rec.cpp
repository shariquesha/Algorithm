#include<bits/stdc++.h>
using namespace std;
int countWays(int m,int n,int x)
{
	int count = 0;
	if( n == 0 && x == 0) return 1;
	
	if( x <= 0 || n == 0) return 0;
	
	for(int i = 1; i <= m ; i++)
	count+=countWays(m,n-1,x-i);
	
	return count;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,x;
		cin>>m>>n>>x;
		cout<<countWays(m,n,x)<<endl;
	}
}
