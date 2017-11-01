#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100 
using namespace std;

void addedge(vector<int>graph[],int s,int d)
{
	graph[s].push_back(d);
}

int main()
{
	int v;
	cin>>v;
	vector<int> graph[MAX];
	int vis[MAX];
	memset(vis,0,sizeof(vis));
	int s,d;
	while(v--)
	{
		cin>>s>>d;
		addedge(graph,s,d);
	}
	return 0;
}
