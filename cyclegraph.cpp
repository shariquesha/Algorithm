//detect loop in a directed graph

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;

/********************************Depth First Traversal of Graph***********************************************/
void printDFS(vector<pair<int,int> >graph[],int i,int * vis)
{
	cout<<i<<" ";
	vis[i] = 1;
	int j = 0;
	for(;j != graph[i].size();j++)
	{
		if(!vis[graph[i][j].first])
		printDFS(graph,graph[i][j].first,vis);
	}
}
void DFS(vector<pair<int,int> >graph[],int s,int *vis)
{
	cout<<s<<" ";
	vis[s] = 1;
	int i = 0;
	
	for(;i != graph[s].size() ; i++)
	{
		//cout<<i;
		if(!vis[graph[s][i].first])
		printDFS(graph,graph[s][i].first,vis);
	}
}

/**************************************************Detect Loop***************************************************/
int recgraph(vector<pair<int,int> >graph[],int i,int * vis,set<int>rec)
{
	vis[i] = 1;
	rec.insert(i);
	int j = 0;
	for(;j != graph[i].size();j++)
	{
		if(!vis[graph[i][j].first])
		recgraph(graph,graph[i][j].first,vis,rec);
		else if(rec.find(graph[i][j].first) == rec.end())
			return 1;
	}
}
int isloop(vector<pair<int,int> >graph[],int * vis)
{
	set<int>rec;
	int i = 0;
	vis[1] = 1;
	rec.insert(1);
	for(;i != graph[1].size();i++)
	{
		if(!vis[graph[1][i].first])
		{
			recgraph(graph,graph[1][i].first,vis,rec);
		}	
		else if(rec.find(graph[1][i].first) == rec.end())
		{
			return 1;
		}
	}
	return 0;
}
/*********************************************Add Edge to Graph with weight**************************************/
void addedge(vector<pair<int,int> >graph[],int s,int d,int w )
{
	graph[s].push_back(make_pair(d,w ));
}

int main()
{
	int v;
	cin>>v;
	vector< pair<int,int> > graph[7];
	int vis[7];
	memset(vis,0,sizeof(vis));
	int s,d,w;
	while(v--)
	{
		cin>>s>>d>>w;
		addedge(graph,s,d,w);
	}
	DFS(graph,1,vis);
	cout<<endl;
	memset(vis,0,sizeof(vis));
	cout<<isloop(graph,vis)<<endl;
	return 0;
}
