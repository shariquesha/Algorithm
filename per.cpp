#include<iostream>
#include<cmath>
using namespace std;

void permute(int *arr,int n)
{
	int t = pow(2,n);
	int i,j,count = 1;
	for(int i = 0; i < t ; i++)
	{
		count = count << i;
		for(int j = 1 ; j <= n ;j++)
		{
			if(count & j)
			cout<<arr[j-1];
		}
		cout<<endl;
    }
}
int main()
{
	int arr[3] = {1,2,3};
	permute(arr,3);
}
