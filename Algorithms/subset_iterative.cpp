/*
  Subset Generation of an array using iterative method
  
  ex: arr = [1,2,3]
      subsets would be: "   "     we can write it as 000
                        1         we can write it as 100
                          2       we can write it as 010
                            3     we can write it as 001
                        1 2       we can write it as 110
                        1   3     we can write it as 101
                          2 3     we can write it as 011
                        1 2 3     we can write it as 111
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<int>arr = {1,2,3};

	int limit = pow(2,arr.size()); //number of subsets = 2^(sizeof(arr))

	for(int i=0;i<limit;i++){
		int temp = i;

		for(int j=arr.size()-1;j>=0;j--){

			int rem = temp % 2;  //finding the binary equivalent of i
			temp/=2;

			if(rem == 0){
				cout<<" ";
			}
			else
			{
				cout<<arr[j]<<" ";
			}
		}
		cout<<endl;
	}
}
