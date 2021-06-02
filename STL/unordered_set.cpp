/*
    Unordered set in C++ STL
    
    -> Uses hashtable in its implementation
    -> randomized order
    -> more efficient than set
    
    Time :  Insert (single element) : O(1)
            Access (single element) : O(1)
            Delete (single element) : O(1)
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_set<string>s;

	s.insert("abc");  //insertion : O(1)
	s.insert("def");
	s.insert("ghi");
	s.insert("abc");

	for(auto &it: s)
	{
		cout<<it<<endl;
	}

	s.erase("abc");  //deletion O(1)
	
	cout<<s.size();

}
