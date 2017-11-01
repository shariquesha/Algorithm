//coin change dp approach
#include<iostream>
#include<cstdlib>

#define ll long long int
using namespace std;

ll minCoin(ll arr[],ll n,ll N)
{
    ll **tab= new ll * [n + 1];
    
    for(ll i = 0; i <= n ; i++ )
    tab[i] = new ll [N + 1];
    
    ll r , q;
    for(ll i = 0 ; i <= n ; i++)
    tab[i][0] = 0;
    
    for(ll i = 0 ; i <= N ; i++)
    tab[0][i] = 0;
    
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= N ; j++)
        {
            if(arr[i - 1] > j )
            {
                tab[i][j] = tab[i - 1][j];    
            }
            else
            {
                q = (j / arr[i - 1]);
                r = tab[i][j % arr[i - 1]];
                if(!(j % arr[i - 1]) || r)
                tab[i][j]= r + q;
                else 
                tab[i][j] = 0;
            }
            
        }
    }
    
    for(int i = 0 ; i <= n ; i++)
	{
		for( int j = 0 ; j <= N ; j++)
		{
			cout<<tab[i][j]<<" ";
		}
		cout<<endl;
	}
	return tab[n][N];
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,N;
	    cin>>n>>N;
	    ll arr[n];
	    
	    for(ll i = 0 ; i < n ; i++)
	    cin>>arr[i];
	 
	    ll result = minCoin(arr,n,N);
	    
	    if(result)
	    cout<<result<<endl;
	    else
	    cout<<"-1"<<endl;
	 }
	
	return 0;
}

