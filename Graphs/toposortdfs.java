package graph;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class toposortdfs {

    public static void main(String[] args){

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<m;i++)
        {
            int u = scn.nextInt();
            int v = scn.nextInt();

            adj.get(u).add(v);
        }

        boolean[] visited = new boolean[n];
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<visited.length;i++)
        {
            if(!visited[i])
            {
                topoDFS(i,adj,visited,st);
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();

        while(!st.isEmpty()){
            ans.add(st.pop());
        }

        System.out.println(ans);
    }

    private static void topoDFS(int i, ArrayList<ArrayList<Integer>> adj, boolean[] visited, Stack<Integer> st) {

        visited[i] = true;

        for(Integer itr : adj.get(i)){

            if(!visited[itr])
            {
                topoDFS(itr,adj,visited,st);
            }
        }

        st.push(i);
    }
}
