/*
    Problem: Given an array of integers find the largest mountain.
    
    Mountain: It is defined as adjacent integers that are strictly increasing until they reach a peak,
    at which they become strictly decreasing
    
    Input: arr = [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
    Output: 9
*/

#include <bits/stdc++.h>
using namespace std;

int findLargestPeak(vector<int>arr)
{
	int maximum = 0;
	int n = arr.size();

	for(int i=1;i<=n-2;)  //start from 1 as 0th element cannot be the peak 
	{                     //end at n-1 as the nth element cannot be the peak
		
    		if(arr[i]>arr[i-1] && arr[i]>arr[i+1])  //checking for peak
		{
			int j=i;
			int count =1;

			while(j>=1 && arr[j]>arr[j-1]) //checking till 1 as when j =1 then j-1 = 0,as when j becomes 0 then i - 1 = -1,will result in segmentation fault
			{
				count++;
				j--;
			}

			while(i<=n-2 && arr[i]>arr[i+1]) //checking till n-2 as when i becomes n-1 then i+1 = (n-1) + 1 = n,which will result segmentationn fault
			{
				count++;
				i++;
			}

			maximum = max(count,maximum);
		}
		else
			i++;
	}

	return maximum;
}



int main()
{
	vector<int>arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

	cout<<findLargestPeak(arr);

	return 0;
}
