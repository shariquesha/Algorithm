#include<iostream>
#include<vector>
using namespace std;
#define MAX 15
int board[MAX][MAX] = {0};

void printSol(vector<int>&sol)
{
    if(sol.empty())
    {
        cout<<"-1";
        return;
    }
    cout<<"[";
    vector<int>::iterator itr ;
    for(itr= sol.begin();itr!=sol.end();itr++)
    {
        cout<<*itr<<" "; 
        
    }
    
    cout<<"]";
}
bool isSafe(int x,int y,int n)
{
     int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < y; i++)
        if (board[x][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=x, j=y; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=x, j=y; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

int nqueen(int y,int n,vector<int>&sol)
{
    if( y == n )
    {
    	printSol(sol);
    	cout<<" ";
    	return 1;
	}
    for(int i = 0 ; i < n ; i++)
    {
        if(isSafe(i,y,n))
        {
            board[i][y] = 1;
            sol.push_back(i+1);
            nqueen(y+1,n,sol);
            board[i][y] = 0;
        	sol.pop_back();
        }
    }
    return 0;
}
int main()
{
	int t;
	
	cin>>t;
	while(t--)
	{
		int n;
	    cin>>n;
	    vector<int> sol;
	    if( n==2 || n==3)
	    {
	        cout<<"-1"<<endl;
	        continue;
	    }
	    nqueen(0,n,sol);
	    cout<<endl;
	}
	return 0;
}
