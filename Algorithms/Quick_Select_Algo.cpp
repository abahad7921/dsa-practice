/*
    Quick select is an algorithm which is used to find the kth smallest number in an unsorted array containing
    distinct numbers in O(logn) time ans O(1) space.
    
    It use concept of partition from QUick Sort algorithm
*/


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int start,int end){

	int pivot = arr[end];
	int pIndex = start;

	for(int i= start;i<end;i++){

		if(arr[i] <= pivot){
			swap(arr[i],arr[pIndex++]);
		}
	}

	swap(arr[end],arr[pIndex]);

	return pIndex;
}


void quickSort(vector<int>& arr,int start,int end,int k){

	int pIndex = partition(arr,start,end);
	// cout<<pIndex<<endl;

	if(pIndex > k){
		quickSort(arr,start,pIndex-1,k);
	}
	else if(pIndex < k)
		quickSort(arr,pIndex + 1,end,k);
	else
		cout<<arr[pIndex]<<endl;
}

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

    vector<int> arr = {1,9,-1,0,222,69,25};
    // after sorting arr = -1 0 1 9 25 69 222

    int start = 0;
    int end = arr.size() - 1;
    int k = 1;
    quickSort(arr,start,end,k-1);

    for(auto i: arr){
    	cout<<i<<" ";
    }

	
}
