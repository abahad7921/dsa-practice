/*
    Given a string find the maximum lenght unique substring
    
    input: abcab
    output: 3
            abc
*/

#include <bits/stdc++.h>
using namespace std;
//time comp: O(n)
int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	string s;
	cin>>s;

	unordered_map<char,int>um;

	int i=0,j=0,maxWindow = INT_MIN,window=0;

	int n = s.length();
	int start;

	while(i<n && j<n){

		if(um.find(s[j])!=um.end() && um[s[j]]>=i){

			i = um[s[j]] + 1;
			window = j - i;
		}

		um[s[j]] = j;
		window++;
		j++;

		if(window > maxWindow){
			maxWindow = window;
			start = i;
		}

	}

	cout<<maxWindow<<endl;

	cout<<s.substr(start,maxWindow);


	
	
}
