/*
    Given an array print all the subsequences whose sum will be equal to the given target
   
*/

#include <bits/stdc++.h>
using namespace std;

void countSubsequence(vector<int>& arr,int index,vector<int>&output,int target,int sum){

	if(index == arr.size()){

		if(sum == target){
			for(auto i: output){
				cout<<i<<" ";
			}
			cout<<endl;
		}

		return;
	}

	sum+=arr[index];  //pick the current element

	output.push_back(arr[index]); //put that element inside the vector

	countSubsequence(arr,index + 1,output,target,sum); //call for the next index

	sum-=arr[index]; //dont pick the current elemet
  
	output.pop_back(); //also if you are not picking it, then remove it from the vector

	countSubsequence(arr,index + 1,output,target,sum);//again call for the next index

}



int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	vector<int>arr = {1,9,22,1,2,0};
	vector<int>output;

	int sum = 0;
	int target = 2;

	countSubsequence(arr,0,output,target,sum);

	
	
}
