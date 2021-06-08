/*
    A prefix sum array contains the sum of the elements of the array from index 1 to that element of the array
    
    for ex: prefix[i] = arr[0] + ...... + arr[i]
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>arr = {1,2,3,4,5};

	//prefix sum code

	vector<int>prefix(arr.size(),0);

	for(int i=0;i<arr.size();i++)
	{
		if(i==0)
		{
			prefix[i] = arr[i];
		}
		else
			prefix[i] = prefix[i-1] + arr[i];
	}

	for(int i: prefix){
		cout<<i<<" ";
	}
  
  return 0;

}
