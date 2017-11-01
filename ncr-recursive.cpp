//find ncr recursive solution

#include<iostream>
#define ll long long int

using namespace std;
ll nCr(int n , int r)
{
	if(n == r || r == 0)
	return 1;
	return nCr(n-1,r-1)+nCr(n-1,r);
}
int main()
{
	int t,n,r;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		cout<<nCr(n,r)<<endl;
	}
	
	return 0;
}
