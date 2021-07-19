/*
    count the frequency of an element in the gievn sorted array
    
    input: 0,0,1,1,2,2,2,2,3,4
           key = 2
    output: 4       
*/

#include <bits/stdc++.h>
using namespace std;
//time : O(logn)
int firstOccurence(vector<int>& arr,int key){

	int low = 0, high = arr.size() -1;

	int mid;
	int ans = -1;

	while(low <= high){

		mid = low + (high - low)/2;

		if(arr[mid] == key){
			ans = mid;
			high = mid - 1;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return ans;
}

int lastOccurence(vector<int>& arr,int key){

	int low = 0, high = arr.size() -1;

	int mid;
	int ans = -1;

	while(low <= high){

		mid = low + (high - low)/2;

		if(arr[mid] == key){
			ans = mid;
			low = mid + 1;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return ans;
}

int main()
{
	
	 #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	vector<int>arr = {0,0,1,1,2,2,2,2,3,4};

// 	cout<<"first occurence = "<<firstOccurence(arr,2)<<endl;
// 	cout<<"last occurence = "<<lastOccurence(arr,2)<<endl;

	cout<<"frequency of 2 = "<<lastOccurence(arr,2) - firstOccurence(arr,2) + 1<<endl;
	
	//we can also solve this by the using STL methods upper bound and lower bound
	
	cout<<upper_bound(arr.begin(),arr.end(),2) - lower_bound(arr.begin(),arr.end(),2)<<endl;
	
	//upper bpund gives the next element > than the key
	//lower bound gives the element >= the key

	return 0;
}
