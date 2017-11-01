/*
              Author : sharq
*/

#include<bits/stdc++.h>
using namespace std;

void indexValue(int a[],int n)
{
    int flag = 0;
    for(int i= 1; i < n ;i++)
    {
        if(i == a[i])
        {
            cout<<a[i]<<" ";
            flag = 1;
        }
    }
    if(!flag)cout<<"Not Found";
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            int arr[n+1];
            for(int i = 1;i <=n;i++)cin>>arr[i];
            indexValue(arr,n+1);
            cout<<endl;
         }
	return 0;
}
