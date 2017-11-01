
/*
              Author : sharq
*/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void getMax(map<string,vector<int> >rec)
{
    map<string,vector<int> >::iterator i;
    i = rec.begin();
    int avg = 0;
    string name;
    int max_avg = (i->second[0] + i->second[1] + i->second[2])/3;
    name = i->first;
    for(i = rec.begin(); i != rec.end() ; i++)   
    {
        avg = (i->second[0] + i->second[1] + i->second[2])/3;
        if(avg > max_avg)
        {
            max_avg = avg;
            name = i->first;
        }
        
    }
    cout<<name<<" "<<max_avg<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
        map<string,vector<int> >rec;
        cin>>n;
        
        int m1,m2,m3;
        while(n--)
        {
            string name;
            cin>>name>>m1>>m2>>m3;
            vector<int>m;
            m.push_back(m1);m.push_back(m2);m.push_back(m3);
            rec.insert(pair<string,vector<int> >(name,m));
        }
        getMax(rec);
    }
	
	return 0;
}
