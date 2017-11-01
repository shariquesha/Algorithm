/*
              Author : sharq
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printSmaller(vector<int> v)
{
    int n = v.size();
    for(int i = 0; i < n ; i++)
    {
        if(v[i] < v[i+1])
        cout<<v[i+1]<<" ";
        else cout<<"-1 ";
    }
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v;
        int n,k;
        cin>>n;
        while(n--)
        {
            cin>>k;
            v.push_back(k);
        }
        printSmaller(v);
        cout<<endl;
    }
	
	return 0;
}
