/*
    Set in C++ STL
    
    Same as maps without a value
    
    Time: 
          Insert (single element): O(log(n))
          Access (single element): O(log(n))
          Find   (single element): O(log(n))
          Delete (single element): O(log(n))
                        
                        
          Insert (n element): O(nlog(n))
          Access (n element): O(nlog(n))
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<string>s;

	s.insert("abc");  //insertion : O(log(n))
	s.insert("def");
	s.insert("ghi");
	s.insert("abc");

	for(auto &it: s)
	{
		cout<<it<<endl;
	}

	s.erase("abc");  //deletion O(log(n))

	if(s.find("abc") != s.end())
		cout<<"abc found in the set"<<endl;
	else
		cout<<"abc not found"<<endl;
	cout<<s.size();

}
