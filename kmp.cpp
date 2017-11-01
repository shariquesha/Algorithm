#include<iostream>
#include<cstring>
using namespace std;

void make_lps(char *ptr,int *lps,int n)
{
    int i = 1 , j = 0;
    lps[0] = 0;
    
    for(; i < n ; i++)
    {
        if(ptr[j] == ptr[i])
        {
            lps[i] = j + 1;
            j++;
        }
        else if( !j)
        {
        	lps[i] = 0 ;
        }
        else if (j)
        {
            j = lps[j-1];
            i--;
		}
    }
    
  // for(i=0;i<n;i++)
    //cout<<lps[i]<<" ";
}
int kmp(char *str,char * ptr)
{
    int n = strlen(str);
    int m = strlen(ptr);
    int lps[m];
    
    make_lps(ptr,lps,m);    
    
    int j = 0;
    int i = 0;
    
    while( i < n && j < m)
    {
    	if( str[i] == ptr[j])
    	{
    		i++;j++;
		}
		else if(str[i] != ptr[j] && j)
			j = lps[j-1];
		else
		i++;
	}
	return (!(i == n && j!=m));
}
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    char str[101],ptr[101];
	    cin>>str>>ptr;
	    if(kmp(str,ptr))
	        cout<<"found"<<endl;
	        else
	            cout<<"not found"<<endl;
	}
	return 0;
}
