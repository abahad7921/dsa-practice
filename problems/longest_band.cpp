/*
    Problem: Given n elements, find the lenght of the largest band is a subsequence
    
    Band: A band is defined as a subsequence which can be reordered in such a manner
    all elements appear consecutive(ie with absolute difference of 1 between neigbouring elements)
    
    A longest is a subsequence which contains the maximum integers
    
    Input: arr = [1,9,3,0,18,5,2,4,10,7,12,6]
    
    Output: 8
*/

#include <bits/stdc++.h>
using namespace std;

//time complexity 0(N)
int largestBand(vector<int>arr)
{
	unordered_set<int>s;

	for(auto i: arr)
	{
		s.insert(i);
	}

	int largest = 0;

	for(auto i: s)
	{
		int count = 0,parent = i-1;

		if(s.find(parent)==s.end())  //if the parent is not present in the set then start looking for the next elements
		{	
      			count = 1;
			int next_no = i+1;

			while(s.find(next_no)!=s.end())
			{
				next_no++;
				count++;
			}

			if(count>largest)
				largest = count; 
		}

	}

	return largest;
}

int main()
{
	vector<int>arr = {1,9,3,0,18,5,2,4,10,7,12,6};

	cout<<largestBand(arr)<<endl;
	
	return 0;
}
