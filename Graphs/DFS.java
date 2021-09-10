/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{   
    public static void DFS(int node,List<List<Integer>> adj,boolean[] visited,List<Integer>ans){
        
        ans.add(node);
        visited[node] = true;
        
        for(int i: adj.get(node)){
            if(!visited[i])
                DFS(i,adj,visited,ans);
        }
    }
  
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner scn = new Scanner(System.in);
	    int n = scn.nextInt();
	    int m = scn.nextInt();
	    
	    List<List<Integer>> adj = new ArrayList<>();
	    for(int i=0;i<=n;i++){
	        adj.add(new ArrayList<Integer>());
	    }
	    
	    for(int i=0;i<m;i++){
	        int u = scn.nextInt();
	        int v = scn.nextInt();
	        
	        adj.get(u).add(v);
	        adj.get(v).add(u);
	    }
	    
	    boolean[] visited = new boolean[n+1];
	    List<Integer> ans = new ArrayList<>();
	    
	    for(int i=1;i<=n;i++){
	        if(!visited[i]){
	            DFS(i,adj,visited,ans);
	           //BFS(i,adj,visited,ans);
	        }
	    }
	    
	    for(int i: ans){
	        System.out.print(i + " ");
	    }
	}
}
