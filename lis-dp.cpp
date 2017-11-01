//lis dp approach

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int retLis(const int *v,const int n)
{
	int i ,j;
	int max = 1;
	int dp[n];
	
	for(i = 0; i < n;i++)
	dp[i] = 1;
	
	for(i = 1; i < n; i++)
	{
		for( j = 0 ; j < i ; j++ )
		{
			if( (v[i] > v[j]) && (dp[i] < dp[j] + 1))
			dp[i] = dp[j] + 1;
		}
		if(max < dp[i])
		max = dp[i];
	}

	//for(i = 0; i < n;i++)
	//cout<<dp[i];
//	cout<<" ";
	return max;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        cout<<retLis(arr,n)<<endl;
    }
    return 0;
}
