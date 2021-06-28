/*
    Generating subset using bitwise operations.
    
    for ex: s = "abc"
            number of subsets possible = 2^3             
*/


#include <bits/stdc++.h>
using namespace std;

void printSubstring(string s){

	int n = s.length();
	int max = (1<<n) -1;  //max subsets possible = 2^n

	for(int i= 0;i<=max;i++){

		int temp = i;
		string ans = "";
		for(int j=s.length()-1;j>=0;j--){

			int rem = temp % 2;

			if(rem == 0){
				// cout<<" ";
				ans += " ";
			}
			else
			{
				// cout<<s[j]<<" ";
				ans = s[j] + ans;
			}

			temp = temp>>1;

		}

		cout<<ans<<endl;
	}



}
int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	string s = "abc";
	printSubstring(s);	

}
