#include <bits/stdc++.h>
using namespace std;

void subsequence(vector<int>& arr,int index,vector<int>&output){

	if(index == arr.size()){

		for(auto i: output){
			cout<<i<<" ";
		}

		cout<<endl;

		return;
	}

	output.push_back(arr[index]); //add it in the output vector

	subsequence(arr,index + 1,output); //call for the next index

	output.pop_back();  //remove it

	subsequence(arr,index + 1,output); //call for the next index wihtout taking the current index element

}



int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	vector<int>arr = {1,9,22};
	vector<int>output;

	subsequence(arr,0,output);

	
	
}
