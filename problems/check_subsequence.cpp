/*
    Given a string s, check if s can be found in a string str by removing some characters(possibly none)
    
    Input: coding minutes
           cines
    Output: true       
*/
#include <bits/stdc++.h>
using namespace std;

//time: O(m + n)  m = length of s1, n= length of s2

bool checkSubsequence(string s1,string s2){

	if(s1 == s2)   //s1 = "coding minutes"  s2 = "cines"
		return true;

	int i=s1.length()-1,j = s2.length() - 1;
	int count = 0;
	while(i>=0 && j>=0){

		if(s1[i]==s2[j]){
			i--;
			j--;
			count++;
		}
		else
			i--;
	}
	// cout<<count<<endl;
	if(count == s2.length())
		return true;

	return false;


}


int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	
	cout<<checkSubsequence(s1,s2)<<endl;
	

}
