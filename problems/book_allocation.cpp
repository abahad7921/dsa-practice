/*
    You are given N number of books. Every ith book has Ai number of pages. 
    You have to allocate books to M number of students. There can be many ways or permutations to do so. 
    In each permutation, one of the M students will be allocated the maximum number of pages. 
    Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages
    allocated to a student is minimum of those in all the other permutations and print this minimum value. 
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& books,int m,int mid){
    
    int total = 1,currentSum = 0;
    
    for(int i=0;i<books.size();i++){
        
        if(currentSum + books[i] > mid){
            currentSum = books[i];
            total++;
            
            if(total > m){
                return false;
            }
        }
        else
        {
            currentSum += books[i];
        }
    }
    
    return true;
}

int minPages(vector<int> books, int m){
  
  int high = 0;
  
  for(auto i: books){
      high+=i;
  }
  int n = books.size();
  int low = books[0];
  int ans = -1;
  
  while(low <= high){
      
      int mid = low + (high - low)/2;
      
      if(isValid(books,m,mid)){
          high = mid - 1;
          ans = mid;
      }
      else
      {
          low = mid + 1;
      }
  }
  
  return ans;
}

signed main(){

// 	#ifndef ONLINE JUDGE
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);
//     #endif 

   vector<int> a = {1,29,44,61};
   int m = 2;

   cout<<minPages(a,m)<<endl;
	
}
