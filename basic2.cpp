/*
              Author : sharq
*/

#include<bits/stdc++.h>
using namespace std;

void CountElements(int *a,int *b,int n)
{
    int max = a[0];
    for(int i = 0 ; i < n ; i++)
    if(max < a[i])
    max = a[i];
    
    int * count = new int[max];
    memset(count,0,max * sizeof(int));
    
    for(int i = 0 ; i < n ; i++)
    {
        count[b[i]]++;
    }
    
    for(int i = 1 ; i < max ; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int i = 0 ; i < n-1 ;i++ )
    {
        cout<<count[a[i]]<<",";
    }
    
    cout<<count[a[n-1]]<<endl;
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;
                int * a = new int[n];
                int * b = new int[n];
                for(int i = 0 ; i < n ; i++)
                cin>>a[i];
                for(int i = 0 ; i < n ; i++)
                cin>>b[i];
                CountElements(a,b,n);
        }
	return 0;
}
