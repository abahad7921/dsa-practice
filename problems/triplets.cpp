/*
      Given n elements and a target sum, you have to
      find all the sorted triplets whose sum is equal to the
      target sum and also print the triplets in sorted order
      
      Input: array: [1,2,3,4,5,6,7,8,9,15]
             target: 18
      Output: [[1,2,15],
              [1,8,9],
              [2,7,9],
              [3,6,9],
              [3,7,8],
              [4,5,9],
              [4,6,8],
              [5,6,7]]       

*/

#include <bits/stdc++.h>
using namespace std;

//time complexity: O(nlogn) + O(n*n) ** sorting + loop traversal * two pointer approach **
//                 O(n^2)

vector< vector<int> > triplets(vector<int>arr,int target)
{
	vector< vector<int> > result;
	//vector<int>tempres;

	sort(arr.begin(),arr.end());

	for(int i=0;i<=arr.size()-3;i++)
	{
		
		int s = i+1, e = arr.size()-1;
	    
	    while(s<e)
	    {
			int currentSum = arr[i];
			currentSum+=arr[s];
			currentSum+=arr[e];

			if(currentSum == target)
			{
				result.push_back({arr[i],arr[s],arr[e]});
				s++;
				e--;
			}
			else if(currentSum > target)
				e--;
			else
				s++;


	    }
	}
	return result;
}

int main()
{
	vector<int>arr = {1,2,3,4,5,6,7,8,9,15};
	int target = 18;

	auto a = triplets(arr,target);

	for(vector<int> x: a)
	{
		for(int y: x)
		{
			cout<<y<<",";
		}
		cout<<endl;
	}


}
