#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<char> >&arr,int i,int j,int n)
{
    if(i >=0 && j>=0 && i<n && j<n && arr[i][j] == 'O')
    {
        return true;
    }

    return false;
}

bool ratInAMaze(vector<vector<char> >&arr,int i,int j,int n,vector<int>&temp,vector<vector<int>>&ans1)
{
    if(i == n-1 && j == n-1)
    {   
        if(arr[i][j] == 'O')
            // ans[i][j] = 1;
            temp.push_back(ans1[i][j]);

        return true;
    }

    if(isPossible(arr,i,j,n))
    {
        // ans[i][j] = 1;
        temp.push_back(ans1[i][j]);

        if(ratInAMaze(arr,i,j+1,n,temp,ans1))
            return true;
        if(ratInAMaze(arr,i+1,j,n,temp,ans1))
            return true;

        // ans[i][j] = 0;
        temp.pop_back();
        return false;
    }

    return false;

}

vector<int> findPath(int n, vector<vector<char>> c){
    ////Write your code below. Do not modify this function or parameters. You can use helper function if needed.   
    
    vector<vector<int> >ans1(n,vector<int>(n,0));

    vector<int>temp;
    int k = 1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){
            ans1[i][j] = k++;
        }
    }

    bool ans = ratInAMaze(c,0,0,n,temp,ans1);

    return temp; 
}
signed main(){

	#ifndef ONLINE JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif 

    vector<vector<char>> arr = {{'O','O','X','O'},
                              {'O','X','O','O'},
                              {'O','O','O','X'},
                              {'X','X','O','O'}};

    // vector<vector<int> >ans(4,vector<int>(4,0));//declare a 2d vector of size n x n and initialize the elments with 0
    
    vector<vector<int> >ans1(4,vector<int>(4,0));

    vector<int>temp;
    int k = 1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){
            ans1[i][j] = k++;
        }
    } 

     cout<<ratInAMaze(arr,0,0,4,temp,ans1)<<endl;

     for(auto i: temp)
        cout<<i<<" ";

}
