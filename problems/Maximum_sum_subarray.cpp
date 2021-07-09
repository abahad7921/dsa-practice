/*
    Find the maximum sum subarray
    
    input: -2, -3, 4, -1, -2, 1, 5, -3
    output: 7
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = a.size();

	int sum = 0,prevSum = INT_MIN;
	for(int i=0;i<n;i++){

		sum+=a[i];

		if(sum > prevSum){
			prevSum = sum;
		}

		if(sum < 0)
			sum = 0;
		// cout<<sum<<" "<<prevSum<<endl;
	}

	cout<<prevSum<<endl;
	
}
