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
                if(!isBipartite(i,adj,color)){
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

    private static boolean isBipartite(int node, ArrayList<ArrayList<Integer>> adj, int[] color) {

        color[node] = 1;
        Queue<Integer> q = new LinkedList<>();
        q.add(node);

        while(!q.isEmpty()){

            Integer n = q.poll();

            for(Integer itr: adj.get(n)){
                if(color[itr] == -1){
                    color[itr] = 1 - color[n];
                    q.add(itr);
                }
                else if(color[itr] == color[n]){
                    return false;
                }
            }
        }

        return true;
    }

}
