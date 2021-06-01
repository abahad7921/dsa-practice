/*
    Maps in C++ STL
    
    -> Map stores the keys in sorted order
    -> The keys should be unique
    -> If the value is not peovided then it will be initialized with null/0/""
    
    Time Complexity:  
                        Insert (single element): O(log(n))
                        Access (single element): O(log(n))
                        Find (single element): O(log(n))
                        Delete (single element): O(log(n))
                        
                        
                        Insert (n element): O(nlog(n))
                        Access (single element): O(nlog(n))
                        
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int,string> mp;  //key value pair {int,string}

	// first way of inerting into the map
	mp[1] = "abc";
	mp[0] = "def";
	mp[3] = "fgh";

	//second way of insertion using insert() function

	mp.insert({5,"sdf"});
  
  //erase() function can take a key or an iterator as an argument
  mp.erase(1);
  
  //find() is used to find if a key is present in the map or not? if key is present then it will return the iterator to it,
  //otherwise it will return an iterator after the end of the map
  
  auto it = mp.find(3); // (*it).first = 3 and (*it).second = "fgh"

	for(auto &i: mp)  //this will take O(nlog(n)) time 
	{
		cout<<i.first<<" "<<i.second<<endl;
	}

}
