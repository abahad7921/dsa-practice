#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int start,int end){

	int i= start;
	int mid = start + (end - start)/2;
	int j = mid + 1;

	vector<int> temp;

	while(i<=mid && j<=end){

		if(arr[i] < arr[j]){
			temp.push_back(arr[i++]);
		}
		else
		{
			temp.push_back(arr[j++]);
		}
	}


	while(i<=mid){
		temp.push_back(arr[i++]);
	}

	while(j<=end){
		temp.push_back(arr[j++]);
	}

	int k = 0;

	for(int i= start;i<=end;i++){
		arr[i] = temp[k++];
	}
}


void mergeSort(vector<int>&arr,int start,int end){

	if(start >= end){
		return;
	}

	int mid = start + (end - start)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid + 1,end);

	merge(arr,start,end);
}


int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

    vector<int> arr = {1,9,-1,0,222,69,25};

    int start = 0;
    int end = arr.size() - 1;
    mergeSort(arr,start,end);

    for(auto i: arr){
    	cout<<i<<" ";
    }

	
}
