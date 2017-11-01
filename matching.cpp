#include<iostream>
using namespace std;
int isFound(char * str,int start, char * ptr)
{
    if(!str[start])
        return 0;
    int i = 0;
    int j = start;
    
    while(ptr[i] && ptr[i+j] == str[j])
    {
        i++;
        j++;
    }
    return ((ptr[i])?isFound(str,start + 1,ptr):1);
}
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    char str[101],ptr[101];
	    cin>>str>>ptr;
	    if(isFound(str,0,ptr))
	        cout<<"found"<<endl;
	        else
	            cout<<"not found"<<endl;
	}
	return 0;
}
