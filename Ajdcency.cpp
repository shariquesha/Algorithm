//Adjecency list representation

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *next;
	int dst;
};

struct Head
{
	struct Node *head;
};

struct graph
{
	struct Head * list;
	int v;	
};

struct graph* newGraph(int v)
{
	struct graph* newgraph = (struct graph*)malloc(sizeof(struct graph));
	
	newgraph -> v = v;
	newgraph -> list = (struct Head *)malloc(v*sizeof(struct Head));
	
	int i = 0;
	for(; i < v ; i++)
	newgraph -> list[i].head = NULL;
	
	return newgraph;
}
struct Node * newNode(int dst)
{
	struct Node * newnode = (struct Node*)malloc(sizeof(Node));
	newnode -> next = NULL;
	newnode -> dst = dst;
	
	return newnode;
} 
void addEdge(struct graph *g ,int s , int d)
{
	
	struct Node * newnode = newNode(d);
	newnode -> next = g -> list[s].head;
	g -> list[s].head = newnode;
	
	struct Node * nn = newNode(s);
	nn -> next = g -> list[d].head;
	g -> list[d].head = nn;
}
void printGraph(struct graph *g)
{
	struct Node * temp;
	int i = 0;
	for(;i < g->v; i++)
	{
		temp = g->list[i].head;
		printf("%d ",i);
		while(temp)
		{
			printf("-> ");                                                         
			printf("%d ",temp->dst);
			temp = temp -> next;
		}
	printf("\n");
	}
}

int main()
{
		 int V = 5;
	struct graph* g = newGraph(V);
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);
	addEdge(g, 1, 4);
	addEdge(g, 2, 3);
	addEdge(g, 3, 4);


	printGraph(g);

	return 0;
}
