/*
              Author : sharq
*/

#include<bits/stdc++.h>
#include<cmath>

using namespace std;

void checkBit(int n)
{
    
    (!(n & (n + 1 )))?cout<<"YES":cout<<"NO";
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            checkBit(n);
            cout<<endl;
         }
	return 0;
}
