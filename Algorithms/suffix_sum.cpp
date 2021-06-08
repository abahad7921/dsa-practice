/*
    A suffix sum array contains the sum of elements of array from nth index to that element
    
    for ex: suffix[i] = arr[n-1] + arr[n-2] + .......+ arr[i]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>arr = {1,2,3,4,5};

  //suffix sum code 

  vector<int>suffix(arr.size(),0);  //intializing the suffix array with 0
	int n = arr.size();
	for(int i=n-1;i>=0;i--)
	{
	 		if(i==(n-1))
	 		{
	 			suffix[i] = arr[i];
	 		}
	 		else
	 			suffix[i] = suffix[i+1] + arr[i];
	}

	for(int i: suffix)
	{
	 	cout<<i<<" ";
	}	
  
  return 0;

}
