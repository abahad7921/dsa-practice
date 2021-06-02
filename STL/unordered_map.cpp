/*
        Unordered map in C++ STL
        
        -> Inbuilt Implementation
        -> More efficient than maps
        -> Uses Hashtable instead of trees
        -> Randomized order
        
        Time : Insertion (single element) : O(1)
               Access (single element): O(1)
               Deletion (single element): O(1)


*/






#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<int,int>mp;  //key value pair {int,int}

	mp[1] = 2;
	mp[3] = 5;
	mp[6] = 0;

	for(auto &i: mp){
		cout<<i.first<<" "<<i.second<<endl;
	}


}
