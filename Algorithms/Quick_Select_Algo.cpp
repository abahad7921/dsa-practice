/*
    Quick select is an algorithm which is used to find the kth smallest number in an unsorted array containing
    distinct numbers in O(logn) time ans O(1) space.
    
    It use concept of partition from QUick Sort algorithm
*/

#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr,int low,int high)  //same logic as Quick Sort
{
	int pivot = arr[high],pIndex = low;

	for(int i=low;i<=high-1;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}

	swap(arr[pIndex],arr[high]);

	return pIndex;
}

void quickSelect(vector<int>& arr,int low,int high,int k)
{
	if(low <high){

	int pIndex = partition(arr,low,high);

	if(pIndex < k)
	{
		quickSelect(arr,pIndex+1,high,k);
	}
	else if(pIndex > k)
	{
		quickSelect(arr,low,pIndex-1,k);
	}
	else
	{
		cout<<arr[pIndex]<<endl;
	} 
}
}

int main()
{
	vector<int> arr = {1,9,4,5,7,6,8,2,3};
	int k = 8;

	quickSelect(arr,0,8,k-1);

	for(int i: arr){
		cout<<i<<" ";
	}
}
