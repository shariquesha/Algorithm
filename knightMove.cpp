//Knight tour problem

#include<iostream>
using namespace std;
#define N 8

int isSafe(int x,int y,int sol[N][N])
{
	return (x >=0 && x < N && y >=0 && y < N && (sol[x][y] == -1));
}

int solveproblem(int x,int y,int move,int sol[N][N])
{
	if( move == N*N )
	return 1;
	
	int movx[8] = {  1, 2, -1, -2, -2, -1,  1,  2 };
    int movy[8] = {  2, 1,  2,  1, -1, -2, -2, -1 };
	
	int i;
	for(i = 0 ; i < N ; i++)
	{
		int newx = x + movx[i];
		int newy = y + movy[i];
		if(isSafe(newx,newy,sol))
		{
			sol[newx][newy] = move;
			if(solveproblem(newx,newy,move+1,sol))
			{
				return 1;
			}
			else
				sol[newx][newy] = -1;
		}
	}
	return 0;
}

void printSol(int sol[N][N])
{
	int i,j;
	for(i = 0; i < N ; i++ )
	{
		for(j = 0; j < N ; j++ )
		{
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int sol[N][N],i,j;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			sol[i][j]=-1;
			sol[0][0] = 0;
	if(!solveproblem(0,0,1,sol))
	cout<<"No solution Exists";
	else
	printSol(sol);
	
	return 0;
}
