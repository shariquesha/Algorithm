/*
		STL Exapmle using map and pair
Author Sharique
e.g.
input :

10
ADD abcd
ADD cdef
ADD abcd
ADD abcd
ADD cdef
ADD ghf
ADD fff
SEARCH abcd
SEARCH cdef
SEARCH rrrr

output:
1 4
2 5
-1 -1


*/
#include <iostream>
#include<map>
#include<utility>

using namespace std;

int main() {

	int n;
	
	cin>>n;
	
	/*
	map to store the string and first and last occurance of string
	key of map is string
	value of map is pair conting first and last
	*/
	map<string,pair<int,int>> m;
	
	string value,query;
	//query number
	int q = 1;
	while( n --)
	{
		cin>>query>>value;
		if(query == "ADD")
		{
			/*
				if value is presnt then set last occurance
			*/
			if(m.find(value) != m.end())
			{
				m[value].second = q;
				q++;
			}
			else
			{
				/*
					if value is not presnt then make a pair 
					value of first and last equals to query number
				*/
				pair<int,int>p(q,q);
				m[value] = p;
				q++;
			}
		}
		else if(query == "SEARCH")
		{
			if(m.find(value) != m.end())
			cout<<m[value].first<<" "<<m[value].second<<endl;
			else
			cout<<"-1 -1"<<endl;
		}
	}
	return 0;
}