#include <bits/stdc++.h>
using namespace std;

int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	vector<int> a = {4,3,-2,1,3,3,-5};
	int n = a.size();

	for(int i=1;i<n;i++){

		int curr = a[i];
		int j = i-1;

		while(j>=0 && a[j]>curr){

			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = curr;
	}

	for(auto i: a){
		cout<<i<<" ";
	}
	
	
}
