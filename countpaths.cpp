/*
              Author : sharq
*/

#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, int m)
{
    if(!n && !m) return 1;
    if(n >= 0 && m >= 0)
    return countPaths(n-1,m)+countPaths(n,m-1);
    else return 0;
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            int m,n;
            cin>>m>>n;
            cout<<countPaths(m-1,n-1)<<endl;
            
         }
	return 0;
}
