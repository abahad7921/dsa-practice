#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > &arr,int row,int col,int n){

	//check for the whole upper column

	for(int i = row - 1 ;i>=0;i--){
		if(arr[i][col] == 1){
			return false;
		}
	}

	//check for the left diagonal

	for(int i = row - 1, j= col - 1; i>=0 && j>=0; i--,j--){

		if(arr[i][j] == 1){
			return false;
		}
	}

	//check for the right diagonal

	for(int i = row - 1, j= col + 1; i>=0 && j < n; i--,j++){

		if(arr[i][j] == 1){
			return false;
		}
	}

	return true;

}

void solveNQueen(vector<vector<int> > &arr,int row,int n,int &ans){

	if(row == n){
	// 	for(int i=0;i<4;i++){

	// 	for(int j=0;j<4;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}

	// 	cout<<endl;
	// }
	// 	cout<<endl<<endl;
		
		ans++;
		return;
	}

	for(int i=0;i<n;i++){

		if(isSafe(arr,row,i,n)){
			arr[row][i] = 1;

			solveNQueen(arr,row + 1,n,ans);

			arr[row][i] = 0;
		}
	}

    
}

int nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.    

	vector<vector<int> > arr(n,{0});

	int ans = 0;
	solveNQueen(arr,0,n,ans);

	return ans;
}

int main()
{
	
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

	

	// cout<<solveNQueen(arr,0);
	cout<<nQueen(1);
	

	return 0;

}
