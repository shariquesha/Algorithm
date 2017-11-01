#include <iostream>
#include<string>
using namespace std;
#define N 26
struct trie
{
    trie *children[N];
    bool isleaf;
};

struct trie * Newnode()
{
    trie * newnode = new trie;
    for(int i = 0 ; i < N ; i++)
    {
        newnode -> children[i] = NULL;
    }
    newnode -> isleaf = false;
    
    return newnode;
}
void insert_trie(string str,trie* root)
{
    trie *current = root;
    int n = str.size();
        for( int i = 0 ; i < n ; i++)
        {
            if(!(current->children[str[i] - 'a']))
            {
                current -> children[str[i] - 'a'] = Newnode();
            }
            current = current -> children[str[i] - 'a'];
        }
        current -> isleaf = true;
}

int search_trie(string ptr, trie *root)
{
    int n = ptr.size();
    int i;
    trie * current = root;
    for(i = 0 ; i < n ; i++)
    {
        if(!(current -> children[ptr[i] - 'a'] ) )
        	return 0;
            current = current -> children[ptr[i] - 'a'];
        
    }
    return current->isleaf;
}
int main() {

    int t;
    cin>>t;
    trie * root = Newnode();
    while(t--)
    {
        int n;
        cin>>n;
        for( int i = 0 ; i < n ; i++)
        {
            string str;
            cin>>str;
            insert_trie(str,root);
        }
        string search;
        cin>>search;
        cout<<search_trie(search,root)<<endl;
    }
	return 0;
}
