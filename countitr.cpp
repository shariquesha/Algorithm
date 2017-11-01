/*
              Author : sharq
*/

#include<bits/stdc++.h>
using namespace std;

int isSafe(int arr[],int i,int itr,int n)
{
    if( i == 0)
    return (arr[i+1] != 0 && arr[i+1] != -itr);
    else if( i == n -1 )
    return (arr[i-1] != 0 && arr[i-1] != -itr);
    else
    return ((arr[i+1] != 0 && arr[i+1] != -itr) || (arr[i-1] != 0 && arr[i-1] != -itr));
}
int countItr(int arr[],int n)
{
    int itr = 0 , count,f = 0;
    while(1)
    {
        itr++;
        count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(!arr[i] && isSafe(arr,i,itr,n))
            arr[i] =-itr;
            else if(!arr[i] )
                count++;
            else
            	f++;
        }
        
        if(count == n ) return -1;
        if(f == n && itr == 1) return 0;
        if( !count) return itr ;
    }
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin >>n;
            int arr[n];
            
            for(int i = 0; i < n ; i++)
            cin>>arr[i];
            
            cout<<countItr(arr,n)<<endl;
         }
	return 0;
}
