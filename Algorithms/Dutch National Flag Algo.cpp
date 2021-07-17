/*
      Dutch National Flag Algo is used to solve the problems like sort an array containing 0s,1s and 2s.
*/

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr){

	//arr = {0,0,1,2,0,1,2,0}

	int low =0,mid = 0,high = arr.size() -1;

	while(mid<=high){

		if(arr[mid] == 0){
			swap(arr[mid++],arr[low++]);
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else
		{
			swap(arr[mid],arr[high--]);
		}
	}


}

int main()
{
	
// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	
	vector<int>arr = {0,0,1,2,0,1,2,0};

	sortArray(arr);

	for(auto i: arr){
		cout<<i<<" ";
	}


}
