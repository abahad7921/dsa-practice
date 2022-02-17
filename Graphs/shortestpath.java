package graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class shortestpath {

    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0;i<n;i++)
        {
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<m;i++)
        {
            int u = scn.nextInt();
            int v = scn.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int[] ans = new int[n];
        ans[0] = 0;

        for(int i=1;i<n;i++)
            ans[i] = Integer.MAX_VALUE;

        shortestPath(0,adj,ans);

        for(int i: ans)
        {
            System.out.print(i + " ");
        }
    }

    private static void shortestPath(int source, ArrayList<ArrayList<Integer>> adj,int[] ans) {

        Queue<Integer> q = new LinkedList<>();
        q.add(source);

        ans[source] = 0;

        while(!q.isEmpty()){

            int node = q.poll();

            for(Integer itr: adj.get(node))
            {
                int distance = ans[node] + 1;

                if(distance < ans[itr]) {
                    ans[itr] = distance;
                    q.add(itr);
                }
            }
        }
    }

}
