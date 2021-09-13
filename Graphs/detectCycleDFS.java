/*
      input: 7 5
             1 2
             2 3
             2 7
             3 5
             7 5
             4 6
       output: yup it has a cycle      
*/

import java.util.*;
import java.lang.*;
import java.io.*;


class Codechef
{   
    public static boolean detectCycleDFS(int node,int parent,boolean[] visited,ArrayList<ArrayList<Integer>>adj){
        
        visited[node] = true;
        
        for(int i: adj.get(node)){
            
            if(visited[i] == false){
                if(detectCycleDFS(i,node,visited,adj) == true)
                    return true;
            }
            else
            {
                if(i != parent)
                    return true;
            }
        }
        
        return false;
    }
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scn = new Scanner(System.in);
		int nodes = scn.nextInt();
		int edges = scn.nextInt();
		
		ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
		
		for(int i=0;i<=nodes;i++){
		    adj.add(new ArrayList<Integer>());
		}
		
		for(int i=0;i<edges;i++){
		    int u = scn.nextInt();
		    int v = scn.nextInt();
		    
		    adj.get(u).add(v);
		    adj.get(v).add(u);
		}
		
		boolean[] visited = new boolean[nodes+1];
		int i=1;
		for(;i<=nodes;i++){
		    if(!visited[i]){
		        if(detectCycleDFS(i,-1,visited,adj) == true)
		        {  System.out.println("yup it has a cycle");
		           break;
		        }
		    }
		}
		
		if(i > nodes){
		    System.out.println("nope it aint got any cycle");
		}
	}
}
