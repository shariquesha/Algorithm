//Rabin Karp
#include<iostream>
#include<cstring>
#include<cmath>
#define base 3

using namespace std;

int newHash(char c1,char c2,int oHash,int m)
{
	int newhash = oHash - (c1 - 'a');
	newhash = newhash / base ;
	newhash = newhash + (c2 - 'a') * pow(base,m-1);
	return newhash;
}
int retHash(char *ptr,int m)
{
	int hash = 0;
	for(int i = 0 ; i < m ; i++)
	{
		hash = hash + (ptr[i] - 'a') * pow(base,i);
	}
	
	return hash;
}
int compString(char *str,char *ptr,int start,int end)
{
	int i = start,j=0;
	while( str[i] == ptr[j] && i < end && j < (end - start))
	{
		i++;
		j++;
	}
	return (i == end);
}
int rabin(char *str, char *ptr)
{
	int n = strlen(str);
	int m = strlen(ptr);
	
	int phash = retHash(ptr,m);
	int thash = retHash(str,m);
	
	if(phash == thash)
	if(compString(str,ptr,0,m))
	return 1;
	
	int i = 0;
	
	while(i < n)
	{
		thash = newHash(str[i],str[i+m],thash,m);
		if(phash == thash)
			if(compString(str,ptr,i+1,i+m+1))
	      		return 1;
	    i++; 
	}
	return 0;
}
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    char str[101],ptr[101];
	    cin>>str>>ptr;
	    if(rabin(str,ptr))
	        cout<<"found"<<endl;
	        else
	            cout<<"not found"<<endl;
	}
	return 0;
}
