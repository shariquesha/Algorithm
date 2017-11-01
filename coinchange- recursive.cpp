//coin change

#include<iostream>

using namespace std;

int coinChange(int *arr,int start , int N , int end)
{
	if( start == end || N < 0) return 0;
	if( N ==0 ) return 1;
	return coinChange(arr,start,N-arr[start],end) + coinChange(arr,start + 1,N,end);
}
int main()
{
	int arr[]= {2,4,6};
	cout<<coinChange(arr,0,3,3)<<endl;
}
