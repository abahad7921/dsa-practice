#include <bits/stdc++.h>
using namespace std;

void firstNonRepeatingCharacter(string s)
{
	if(s.length() == 0)
	{
		cout<<-1<<endl;
		return;
	}

	unordered_map<char,int>um;

	queue<char>q;

	for(int i=0;i<s.length();i++)
	{
		um[s[i]]++;

		if(q.size() == 0)
		{
			if(i == 0)
				cout<<s[i]<<" ";
			else
				cout<<-1<<" ";

			q.push(s[i]);
		}
		else
		{
			if(um[q.front()] == 1)
				cout<<q.front()<<" ";
			else

		}
	}
}

int main()
{
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    string s = "aabccbcd";

    firstNonRepeatingCharacter(s);

    

	return 0;

}
