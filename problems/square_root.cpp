/*
    Find the square root of the given number by p places wihtout using any library functions
    
    input: 10 3
    output: 3.162
*/

#include <bits/stdc++.h>
using namespace std;

float squareRoot(int n,int p){

	int low = 0, high = n,mid;

	float ans;

	while(low <= high){

		int mid = low + (high - low)/2;

		if(mid * mid == n){
			return mid;
		}
		else if(mid * mid < n){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}


	float inc = 0.1;

	for(int i = 1;i<= p;i++){

		while(ans * ans <= n){
			ans += inc;
		}

		ans -= inc;

		inc = inc/10.0;
	}

	return ans;
}

int main()
{
	
// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	int n,p;
	cin>>n>>p;

	cout<<squareRoot(n,p);
	
  return 0;
}
