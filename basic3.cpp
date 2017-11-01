/*
              Author : sharq
*/
#include<bits/stdc++.h>
using namespace std;

void countUncommon(string s1,string s2)
{
    set<char>h1,h2,h3;
    string::iterator i;
    
    for(i = s1.begin(); i != s1.end(); i++)
    h1.insert(*i);
    
    for( i = s2.begin(); i !=s2.end(); i++)
    h2.insert(*i);
    
    for( i = s1.begin() ; i !=s1.end() ; i++)
        if(h2.find(*i) == h2.end())
        h3.insert(*i);
    
    for( i = s2.begin(); i !=s2.end(); i++)
    if(h1.find(*i) == h1.end())
        h3.insert(*i);
        
    set<char>::iterator j;
    
    for(j = h3.begin();j != h3.end();j++)
    cout<<*j;
    cout<<endl;
    
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
            
            string str1,str2;
            cin>>str1>>str2;
            countUncommon(str1,str2);
        }
	return 0;
}
