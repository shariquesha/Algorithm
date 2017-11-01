#include<iostream>
#define MAX 1000
using namespace std;

int MIN(int a,int b)
{
	return ((a>b)?b:a);
}
int min(int a,int b, int c)
{
	return MIN(a,MIN(b,c));
}
int DistanceCost(int mat[3][3],int x,int y, int n , int m){
	
	if(x >= n || y >= m) return MAX;
	if(x == n-1 && y == m-1) return mat[x][y];
	return mat[x][y] + min(DistanceCost(mat,x,y+1,n,m),DistanceCost(mat,x+1,y+1,n,m),DistanceCost(mat,x+1,y,n,m));
}
int main()
{
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout<<DistanceCost(cost,0,0,3,3)<<endl;
   cout<<DistanceCost(cost,1,0,3,3)<<endl;
   cout<<DistanceCost(cost,2,0,3,3)<<endl;
   cout<<DistanceCost(cost,0,2,3,3)<<endl;
   cout<<DistanceCost(cost,1,2,3,3)<<endl;
   cout<<DistanceCost(cost,2,2,3,3)<<endl;
   return 0;
}
