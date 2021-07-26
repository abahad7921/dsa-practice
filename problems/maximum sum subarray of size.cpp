/*
    Given an array of size n find the maximum sum whch can be obtained from the subarray of size k
    
    input: 0,1,1,0,1,2,0,1,2
           k = 3
    output: 3
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>&arr,int k){

    if(k < 1){
        return 0;
    }

    int sum = 0,maximum = -1;

    int i = 0, j = 0,n = arr.size();

    while(j < n){

        sum+=arr[j];

        if( (j - i + 1) > k){

            sum-=arr[j]; //get the current window sum as of now

            maximum = max(maximum,sum);

            sum-=arr[i]; //move the window forward
            sum+=arr[j]; //get the next element

            i++;
        }

        j++;
    }

    

        // // another method

        // //first get the sum of first k elements

        // int sum = 0;


        // for(int i = 0;i < k;i++){
        //     sum+= arr[i];
        // }

        // int maximum = sum;
        
        // int j = k;
        // int i = 0;
        // int n = arr.size();
        // while(j < n){
            
        //     sum+=arr[j];
        //     sum-=arr[i];

        //     maximum = max(maximum,sum);

        //     j++;
        //     i++;

        // }

    

    return maximum;


}

int main(){

	 #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    vector<int> arr = {0,1,1,0,1,2,0,1,2};

    cout<<maximumSumSubarray(arr,3);
    
    return 0;
}
