#include <bits/stdc++.h>
using namespace std;
//time : O(n)
int kadanesAlgo(vector<int>&arr)
{
	int localSum=0,maxSum = INT_MIN;  

	for(auto i: arr)
	{
		localSum+=i;
		maxSum = max(maxSum,localSum);  
		if(localSum<0)   //we are removing the negative sum
			localSum=0;
	}

	return maxSum;
}

int main()
{
	vector<int>arr = {-1,2,3,4,-2,6,-8,3};

	cout<<"maximum subarray sum is "<<kadanesAlgo(arr)<<endl;
}
