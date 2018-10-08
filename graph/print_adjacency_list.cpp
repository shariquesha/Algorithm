/*
 g++ print_adjacency_list.cpp -o print_adjacency_list
 ./print_adjacency_list < print_adjacency_list_input.txt
*/

#include<iostream>
#include<vector>

using namespace std;

void make_list(vector<int> adj_list[], int start, int end)
{
  adj_list[start].push_back(end);
  adj_list[end].push_back(start);

}

void print_list(vector<int> adj_list[], int v)
{
  for(int i = 0 ; i < v ; i++)
  {
    cout<<i;
    for(vector<int>:: iterator j = adj_list[i].begin(); j != adj_list[i].end(); j++)
    {
      cout<<"-> "<<*j;
    }
    cout<<endl;
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int v,e,start,end;
    cin>>v>>e;
    vector<int> adj_list[v];
    for(int i = 0; i < e; i++)
    {
      cin>>start>>end;
      make_list(adj_list,start,end);
    }
    print_list(adj_list,v);
  }
  return 0;
}






