 #include <bits/stdc++.h>
using namespace std;


bool isRedundentParenthesis(string s)
{
	if(s.length() == 0)
		return false;
	
	stack<char>st;

	for(auto i: s)
	{
		if(i != ')')
		{
			st.push(i);
		}
		else
		{
			bool found = false;

			while(!st.empty() && st.top()!='(')
			{
				char ch = st.top();

				if(ch == '+' || ch == '-' || ch=='*' || ch == '/')
					found = true;

				st.pop();
			}

			st.pop();

			if(found == false)
				return true;
		}
	}

	return false;
}

int main()
{
	
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

    string s = "(a + b)";

    if(isRedundentParenthesis)
    	cout<<"does contain redundant parenthesis";
    else
    	cout<<"does not contain redundant parenthesis";

	return 0;

}
