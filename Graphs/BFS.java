/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{   
    //time: O(n + e) space: O(n + e) + O(n) + O(n)
	
    public static void BFS(int i,ArrayList<ArrayList<Integer>>adj,boolean visited[],ArrayList<Integer>ans){
        
        Queue<Integer> q = new LinkedList<>();
        q.add(i);
        visited[i] = true;
        
        while(!q.isEmpty()){
            
            int node = q.poll(); //get the top of Queue
            ans.add(node);
                
            for(Integer itr: adj.get(node)){
                if(!visited[itr]){
                    q.add(itr);
                    visited[itr] = true;
                }
            }
        }
    }
    
    
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int m = scn.nextInt();
		
		ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
		
		for(int i=0;i<=n;i++){
		    adj.add(new ArrayList<Integer>());
		}
		
		for(int i=0;i<m;i++){
		    int u = scn.nextInt();
		    int v = scn.nextInt();
		    
		    adj.get(u).add(v);
		    adj.get(v).add(u);
		}
		
		for(ArrayList<Integer> a: adj){
		    System.out.println(a);
		}
		
		boolean[] visited = new boolean[n+1];
		
		for(int i=0;i<=n;i++)
		{
		    visited[i] = false;
		}
		ArrayList<Integer>ans = new ArrayList<>();
		for(int i=1;i<=n;i++){
		    
		    if(!visited[i]){
		        BFS(i,adj,visited,ans);
		    }
		}
		
		for(int i: ans){
		    System.out.printf(i + " ");
		}
	}
}
