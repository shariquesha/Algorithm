#include<iostream>
using namespace std;
#define N 9

int isSafe(int mat[N][N],int x, int y,int n)
{
    for(int i = 0; i < N ; i++)
    {
        if((mat[x][i] == n) || (mat[i][y] == n))
        return 0;
    }
    return 1;
}
void printSol(int mat[N][N])
{
    for(int i = 0 ;i < N ; i++)
        for(int j = 0; j < N ; j++)
            cout<<mat[i][j]<<" ";
}
void solve(int mat[N][N], int x , int y)
{
    for( int i = 1 ; i <= N ; i++)
    {
        if(!mat[x][y])
        {
            if(isSafe(mat,x,y,i))
            {
                mat[x][y] = i;
                
                if(y + 1 < N )
                solve(mat,x,y+1);
                else if ( x + 1 < N)
                solve(mat,x + 1,0);
                else
                return;
                
                mat[x][y] = 0;
            }
        }
        else
        {
                if(y + 1 < N )
                solve(mat,x,y+1);
                else if ( x + 1 < N)
                solve(mat,x + 1,0);
                else
                return;
        }
        
    }
}
int main()
 {
    int t,mat[N][N];
    cin>>t;
    while(t--)
    {
        for(int i = 0 ; i < N ; i++)
        for(int j = 0; j < N ; j++)
        cin>>mat[i][j];
        
        
        solve(mat,0,0);
        printSol(mat);
    }
	return 0;
}
