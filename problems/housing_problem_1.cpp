/*
    Problem:
    You want to buy K acres of land to build a house. You want to find all segments of contiguous
    plots (i.e a subsection in the subsequence) of whose sum is exactly K.
    
    also find the smallest window of subsection who sum is equal to K.
    
    input: 1,3,2,1,4,1,3,2,1,1
           k = 8
    output: 2 - 5
            4 - 6
            5 - 9
*/

#include <bits/stdc++.h>
using namespace std;

void housingProblem(vector<int> a,int k){

	int minWindow = INT_MAX;

	int i=0,j=0,currenSum=0;
	int n = a.size();
	while(j<n){
    
			currenSum+=a[j];
			j++;

			while(currenSum > k && i<j){
				currenSum-= a[i];
				i++;
			}

			if(currenSum == k){
				cout<<i<<" - "<<j-1<<endl;
				minWindow = min(minWindow,abs(j-1-i));
      }
	}

	cout<<minWindow<<endl;

}

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	vector<int> a = {1,3,2,1,4,1,3,2,1,1};
	// int n = a.size();

	housingProblem(a,8);
	
	
}
