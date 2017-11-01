#include<iostream>
using namespace std;

int isSafe(int x,int y,int m[MAX][MAX],int n)
{
	return (x >= 0 && x < n && y >= 0 && y < n && m[n-1][n-1] == 1);
}
