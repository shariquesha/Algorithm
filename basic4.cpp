/*
              Author : sharq
*/

#include<bits/stdc++.h>
using namespace std;

int countGrps(int *arr,int n,int count,int sum)
{
    if(n < 0 || (count == 3 && (sum%3)))return 0;
    
    if(count == 3 && !(sum%3) )return 1;
    
    if(count == 2 && !(sum%3) ) return 1 + countGrps(arr,n-1,count+1,sum);
    
    return countGrps(arr,n-1,count+1,sum+arr[n-1])+countGrps(arr,n-2,count+1,sum+arr[n-1]);
    
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
            
            for(int i = 0 ; i < n ;i++)
            cin>>arr[i];
            
            cout<<countGrps(arr,n,0,0)<<endl;
         }
	return 0;
}
