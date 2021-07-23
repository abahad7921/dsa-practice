#include <bits/stdc++.h>
using namespace std;

void generatePermutations(string s,string ans,set<string>&us){

    if(s.length() == 0){
        // cout<<ans<<endl;
        us.insert(ans);
        return;
    }

    for(int i=0;i<s.length();i++){

        char ch = s[i];

        string left = s.substr(0,i);
        string right = s.substr(i+1);

        string rest = left + right;

        generatePermutations(rest,ans + ch,us);
    }
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.

    vector<string> ans;

    set<string>us;
    generatePermutations(s,"",us);

    for(auto i: us){
        // cout<<i<<" ";
        ans.push_back(i);
    }

    return ans;

}

int main() {

//     #ifndef ONLINE JUDGE
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);
//     #endif 
              
	string s;
    cin>>s;

    // generatePermutations(s,"");
    findSortedPermutations(s);

	return 0;
}
