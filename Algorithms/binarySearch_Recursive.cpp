#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr,int target,int start,int end){
  
	int pos = -1;

	while(start<=end){

		int mid = start + (end - start)/2;  //it will prevent overflow

		if(arr[mid] == target)
			return mid;
		else if(arr[mid] < target)
			start = binarySearch(arr,target,mid + 1,end);
		else
			end = binarySearch(arr,target,start,mid - 1);
	}

	return -1;
}

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	vector<int>arr = {1,9,22,444,5,21,26};

	sort(arr.begin(),arr.end());

	int target = 26;
	int start = 0;
	int e = arr.size() - 1;

	cout<<binarySearch(arr,target,start,e)<<endl;

	for(auto i: arr){
		cout<<i<<" ";
	}
	
}
