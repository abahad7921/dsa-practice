/*
    replace spaces with "%20"
    
    input: "hello world"
    output: "hello%20world"
*/

#include <bits/stdc++.h>
using namespace std;

void replaceSpaces(char* s){

	int space = 0;

	for(int i=0;i<strlen(s);i++){
		if(s[i] == ' ')
			space++;
	}

	int idx = strlen(s) + space*2;
	s[idx] = '\0';

	for(int i= strlen(s)-1;i>=0;i--){
		if(s[i]==' '){
			s[idx-1] = '0';
			s[idx-2] = '2';
			s[idx-3] = '%';

			idx-=3;
		}
		else
		{
			s[idx-1] = s[i];
			idx--;
		}
	}

}


int main(){

// 	 #ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif


	char s[1000] = "hello world";
	replaceSpaces(s);

	cout<<s<<endl;
	

}
