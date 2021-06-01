/*
  Problem Statement:
  Given an array containing N integers and a number S denoting a target sum.
  Find two distinct integers that can pair up to form target sum. (Let us assume there will be only one such pair) 
  
  Input: array = [10,5,2,3,-6,9,11]
         S = 4
         
  Output: [10, -6] or [-6, 10]       

*/
//time: O(n)  ** O(1) for lookup and O(n) for traversal


#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(int arr[],int sum)
{
	vector<int>result;

	unordered_set<int>s;
    
    int n = 7;

    for(int i=0;i<n;i++)
    {
    	if( s.find((sum - arr[i]))!= s.end() )
    	{
    		result.push_back(arr[i]);
    		result.push_back((sum - arr[i]));

    		return result;
    	}

    	s.insert(arr[i]);
    }

    return {};

}

int main()
{
	int arr[] = {10,5,2,3,-6,9,11};  //initialized with the sample values
    int sum = 4;

    vector<int> output = pairSum(arr,sum);

    cout<<output[0]<<" "<<output[1];
}
