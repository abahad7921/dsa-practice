package com.company;

import java.util.*;

public class Main {

    static class Node{
        int first;
        int second;

        public Node(int first,int second){
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();//no. of nodes
        int m = scn.nextInt();//no. of edges

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

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

        int i=1;
        for(;i<=n;i++){
            if(!visited[i]){
                if(detectCycleBFS(i,adj,visited)){
                    System.out.println("yes there is a cycle");
                    break;
                }
            }
        }

        if(i>n){
            System.out.println("nope there is no cycle in the graph");
        }
    }

    private static boolean detectCycleBFS(int i, ArrayList<ArrayList<Integer>> adj, boolean[] visited) {

        //this method is implemented using BFS technique

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(i, -1));
        visited[i] = true;

        while(!q.isEmpty()){

            int ele = q.peek().first;
            int par = q.peek().second;
            q.remove();
            for(Integer itr: adj.get(ele)){

                if(!visited[itr]){
                    q.add(new Node(itr,ele));
                    visited[itr] = true;
                }
                else
                {
                    if(par != itr){
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
