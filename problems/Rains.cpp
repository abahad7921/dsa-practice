/*
  Problem:  Given an array of heights, find how much water can be held in bw them
            
           Input: heights = [0,1,0,2,1,0,1,3,2,1,2,1]
           
           Output: 6
*/

 #include <bits/stdc++.h>
using namespace std;

//time: O(n)
int trappedwater(vector<int>arr)
{
	int water = 0;

	vector<int>left(arr.size(),-1);
	vector<int>right(arr.size(),-1);

	//arr = 1,0,1,2,3,4,5,6
	//left = 1,1,1,2,3,4,5,6
	for(int i=0;i<arr.size();i++)
	{
		if( left[i] < arr[i] )
			left[i] = arr[i];

		if(i!=0 && left[i]<left[i-1])
			left[i] = left[i-1];
	}
  
  //arr = 1,0,1,2,3,4,5,6
  //right = 6,6,6,6,6,6,6,6 
  
	for(int i= arr.size()-1;i>=0;i--)
	{
		if(right[i]<arr[i])
			right[i] = arr[i];

		if(i!=(arr.size()-1) && right[i]<right[i+1])
			right[i] = right[i+1];

	}

	// for(int i: left)
	// 	cout<<i<<" ";

	// cout<<endl;

	// for(int i:right)
	// 	cout<<i<<" ";

	for(int i = 0;i<arr.size();i++){
		water = water + min(left[i],right[i]) - arr[i];
	}

	return water;

}

int main()
{
	vector<int>arr = {0,1,0,2,1,0,1,3,2,1,2,1};


	cout<<trappedwater(arr);
  
  return 0;
		
}
