/*
  Given a string find its subsequences and sort them lexicographically if their length is same, otherwise sort them numerically.
  
  input: abc
  output: ,a,b,c,ab,ac,bc,abc
*/

#include <bits/stdc++.h>
using namespace std;

void generateSubsequence(string input,string output,vector<string> &ans){

	if(input.length() == 0){
		ans.push_back(output);
		return;
	}

	char ch = input[0];
	string reduced_input = input.substr(1);

	//first call taking the character
	generateSubsequence(reduced_input,output + ch,ans);
	//second call without taking the character
	generateSubsequence(reduced_input,output,ans);
}

bool compare(string s1,string s2){
	if(s1.length() == s2.length())
		return s1<s2;
	else
		return s1.length() < s2.length();
}

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	string input;
	cin>>input;

	string output = "";
	vector<string>ans;
	generateSubsequence(input,output,ans);

	sort(ans.begin(),ans.end(),compare);

	for(auto i: ans){
		cout<<i<<",";
	}

}
