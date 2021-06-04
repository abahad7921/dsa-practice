#include <bits/stdc++.h>
using namespace std;

int main()
{

	vector<pair<int,int> > vp = {{1,2},{3,4},{5,6}};

	vector<pair<int,int> > :: iterator it; //declare an iterator

	//first method of accessing 
	for(int i=0;i<vp.size();i++)
	{
		cout<<vp[i].first<<" "<<vp[i].second<<endl;
	}


	//second method of accessing

	for(it = vp.begin(); it!=vp.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;  //alternatively we can use it->first <=> (*it).first  and it->second <=> (*it).second
	}

	//third method of accessing
	for(pair<int,int> i: vp)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}

	//alternate way using auto keyword

	for(auto i: vp)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}

}
