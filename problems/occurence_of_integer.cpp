/*
    Find the occurence of an integer in the array:
    
    ex: arr = [1, 2, 2, 2, 2, 3, 4, 7, 8, 8]
        target = 2
        
        ans = 4
*/
//Using binary search
#include <bits/stdc++.h>
using namespace std;

void improvedBinarySearch(vector<int> &arr){
    
    int target = 8;
    
    int low =0,high = arr.size()-1,mid,first,last;
    
    while(low<=high){
        int mid = low + (high - low)/2;
        
        if(arr[mid]>=target){
            first = mid;
            high = mid-1;
        }
        else
            low = mid + 1;
    }
    
    low = 0;
    high = arr.size() -1;
    
    while(low<=high){
        mid = low + (high - low)/2;
        
        if(arr[mid] <= target)
        {
            last = mid;
            low = mid + 1;
        }
        else
            high = mid -1;
            
    }
    cout<<first<<" "<<last<<endl;
    cout<<abs(last - first) + 1<<endl;
}


int main() {
	
	vector<int>arr ={1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
	
	improvedBinarySearch(arr);
	
	return 0;
}
