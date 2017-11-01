/*
              Author : sharq
*/

#include<bits/stdc++.h>

using namespace std;
int isFound(int *arr,int n,int p)
{
    set<int>s;
    
    for(int i = 0 ; i < n ; i++)
    {
        if( !(p%arr[i]) && s.find(p/arr[i]) != s.end() )
        return 1;
        
        s.insert(arr[i]);
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        int *arr = new int[n];
        
        for(int i = 0; i < n ; i++)
        cin>>arr[i];
        
        if(isFound(arr,n,p))cout<<"Yes";
        else cout<<"No";
        cout<<endl;
        
    }
	
	return 0;
}
