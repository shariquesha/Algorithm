//edit prolem - Naive approach
#include<iostream>
#include<cstring>

using namespace std;
int MIN(int a,int b)
{
	return (a > b)?b:a;
}
int min(int a , int b , int c)
{
	return min(a,min(b,c));
}
int EditDistance(char * str1,char *str2,int n,int m)
{
	if(n < 0 || m < 0 ) return 0;
	if(str1[n-1] == str2[m-1])
	return EditDistance(str1,str2,n-1,m-1);
	
	else
	return 1 + min(EditDistance(str1,str2,n-1,m-1),EditDistance(str1,str2,n-1,m),EditDistance(str1,str2,n,m-1));
}

int main()
{
	char *s1 = "aa";
	char *s2 = "aaaa";
	cout<<EditDistance(s1,s2,strlen(s1),strlen(s2))<<endl;
}
