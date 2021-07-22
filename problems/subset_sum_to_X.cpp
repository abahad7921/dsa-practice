/*
    count the number of subsets whose sum will be equal to X.
    
*/

#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int>&arr,int X,int index){

	// if(index == arr.size()){

	// 	int sum = 0;
	// 	for(auto i: subset){
	// 		sum += i;
	// 	}

	// 	if(sum == X)
	// 		return 1;

	// 	return 0;
	// }

	// subset.push_back(arr[index]);

	// int inc = countWays(arr,X,subset,index + 1);

	// subset.pop_back();
	// int no = countWays(arr,X,subset,index + 1);

	// return inc + no;


	//better approach

	if(index == arr.size()){

		if(X == 0){
			return 1;
		}

		return 0;
	}

	int inc = countWays(arr,X - arr[index],index + 1);
	int exc = countWays(arr,X,index+1);

	return inc + exc;

}

int main()
{
	
// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	vector<int> arr = {1,2,3,4,5};
	int X = 3;

	vector<int>subset;

	// cout<<countWays(arr,X,subset,0)<<endl;
	cout<<countWays(arr,X,0)<<endl;

}
