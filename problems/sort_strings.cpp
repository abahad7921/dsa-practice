/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric
Sample Output
-------------
82 12
77 13
92 022
*/
#include <bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str,int key){

	//string tokeniser 
	// hello how are you

	char *s = strtok( (char *)str.c_str(), " ");
	while(key>1){
		s = strtok(NULL," ");
		key--;
	}
	return (string)s;
}

int numeric(string s){

	int ans = 0;
	int p = 1;

	for(int i=0;i<s.length();i++){
		ans += ((s[i]-'0')*p);
		p = p*10;
	}

	return ans;
}

bool numericSort(pair<string,string>s1,pair<string,string> s2){

	string a = s1.second;
	string b = s2.second;

	return numeric(a) < numeric(b);
}

bool lexicoGraphicSort(pair<string,string>s1,pair<string,string> s2){

	string a = s1.second;
	string b = s2.second;

	return a<b;
}

int main(){

	#ifndef ONLINE JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif 

	int n;
	cin>>n;

	vector<string>vs;
	string s;

	cin.get();
	
	for(int i=0;i<n;i++){
		getline(cin,s);
		vs.push_back(s);
	}


	int key;
	string order,comparison;
	cin>>key>>order>>comparison;
	// for(auto i: vs){
	// 	cout<<i<<endl;
	// }

	vector<pair<string,string> > vp;

	for(int i=0;i<vs.size();i++){

		vp.push_back({vs[i],extractStringAtKey(vs[i],key)});
	}

	
	if(comparison == "numeric"){
		sort(vp.begin(),vp.end(),numericSort);
	}
	else
	{
		sort(vp.begin(),vp.end(),lexicoGraphicSort);
	}


	if(order == "true"){
		reverse(vp.begin(),vp.end());
	}

	for(auto i: vp){
		cout<<i.first<<endl;
	}

}
