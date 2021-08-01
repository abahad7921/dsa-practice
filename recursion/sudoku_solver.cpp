#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> &input,int i,int j,int n,int k){

    //first check for the respective row and column

    for(int a = 0;a<n;a++){
        if(input[i][a] == k){
            return false;
        }

        if(input[a][j] == k){
            return false;
        }
    }

    //check for the subgrid in which the element belongs

    int sx = (i/3) * 3;
    int sy = (j/3) * 3;

    for(int a = sx;a<sx + 3;a++){

        for(int b = sy;b<sy + 3;b++){

            if(input[a][b] == k){
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<int> >& input,int i,int j,int n){

    if(i == n){
        return true;
    }

    if(j == n){
        return solve(input,i + 1,0,n); 
    }

    if(input[i][j] !=0){
        return solve(input,i,j+1,n);
    }

    for(int k = 0;k<=9;k++){

        if(isSafe(input,i,j,n,k)){
            input[i][j] = k;

            if(solve(input,i,j+1,n)){
                return true;
            }
        }
    }

    input[i][j] = 0;

    return false;
}

vector<vector<int> > solveSudoku(vector<vector<int> > input){
    
    bool ans = solve(input,0,0,9);

    return input;  
}

int main() {

//     #ifndef ONLINE JUDGE
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);
//     #endif 

    vector<vector<int> > input = {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    vector<vector<int> > output = solveSudoku(input);
    
    for(auto i: output){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }    
	
	return 0;
}
