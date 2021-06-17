#include<bits/stdc++.h>
using namespace std;


void printBinary(int n){

	for(int i=10;i>=0;i--){
		cout<< ((n >>i)&1);
	}

	cout<<endl;
}

int main(){


	//basic bit manipulation techniques

	int n = 9;

	printBinary(n);

	//to make its 1st bit set we can do bitwise OR
	int i=1;
	printBinary(n | 1<<i);  // 1001 | 0010

	//to make its 0th bit unset we can do bitwise AND
	i = 0;
	printBinary(n & (~(1<<i))); // 1001 & ~(0001) = 1001 & 1110

	//count the number of set bits
	int count = 0;
	for(int i=5;i>=0;i--){
		if((n & (1<<i)) != 0)
			count++;
	}

	cout<<count<<endl;

	//another method

	cout<< __builtin_popcount(n);  //if n is long long then use __builtin_popcountll(n)

	return 0;
}
