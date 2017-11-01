//stoi

#include<bits/stdc++.h>

using namespace std;

int stoi(char s[])
{
	int n = strlen(s);
	int num = 0;
	
	for(int i = 0 ; i < n ;i++)
	num = num * 10 + s[i]-'0';
	
	
	return num;
}
int main()
{
	char s[]="123";
	cout<<stoi(s);
}
