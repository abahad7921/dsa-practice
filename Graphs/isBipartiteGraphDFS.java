package com.company;

import java.util.*;

public class Main {


    public static void main(String[] args) {

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

        int[] color = new int[nodes+1];
        for(int i=0;i<color.length;i++){
            color[i] = -1;
        }

        int i=1;
        for(;i<=nodes;i++){

            if(color[i] == -1){
                if(!isBipartiteDFS(i,adj,color)){
                    break;
                }
            }
        }

        if(i < nodes){
            System.out.println("nope the graph cant be bipartite");
        }
        else
        {
            System.out.println("yes the graph is bipartite");
        }



    }
 
    public static boolean isBipartiteDFS(int node, ArrayList<ArrayList<Integer>> adj, int[] color){
        
        if(color[node] == -1)
            color[node] = 1;

        for(Integer itr: adj.get(node)){
            if(color[itr] == -1){
                color[itr] = 1 - color[node];

                if(!isBipartite(itr,adj,color)){
                    return false;
                }
            }
            else if(color[itr] == color[node]){
                return false;
            }
        }

        return true;
    }



}
