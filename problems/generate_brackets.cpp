/*
  given n , generate how many balances bracket sequence you can form
*/

#include <bits/stdc++.h>
using namespace std;

void generateBrackets(string output,int n,int open,int close,int index){

	if(index == 2*n){

		cout<<output<<endl;
		return;
	}

	if(open < n){
		generateBrackets(output + '(',n,open + 1,close,index + 1);
	}

	if(close < open){
		generateBrackets(output + ')',n,open,close + 1,index + 1);
	}
}

int main()
{
	
// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	int n;
	cin>>n;

	string output;

	generateBrackets(output,n,0,0,0);


	return 0;

}
