#include <bits/stdc++.h>
using namespace std;
//Selection Sort time: O(n^2)
void selectionSort(vector<int> &arr){
    
    int min,n = arr.size(),minIdx;
    
    for(int i=0;i<n-1;i++){
        min = arr[i];
        minIdx = i;
        
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIdx= j;
            }
        }
        
        swap(arr[i],arr[minIdx]);
    }
}

void printArray(vector<int> &arr){
    
    for(int i: arr){
        cout<<i<<" ";
    }
    
    cout<<endl;
}

int main() {
	
	vector<int>arr = {1,29,6,33,91,55};
	
	cout<<"before sorting: "<<endl;
	printArray(arr);
	
	selectionSort(arr);
	cout<<"after sorting: "<<endl;
	printArray(arr);
	
	
	return 0;
}
