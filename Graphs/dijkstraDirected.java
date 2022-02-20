package graph;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Nodes  implements Comparator<Nodes> {
    private int distance,vertex;

    Nodes(){}

    Nodes(int distance,int weight)
    {
        this.distance = distance;
        this.vertex = weight;
    }

    int getDistance()
    {
        return this.distance;
    }

    int getWeight(){
        return this.vertex;
    }

    @Override
    public int compare(Nodes node1, Nodes node2)
    {
        if (node1.distance < node2.distance)
            return -1;
        if (node1.distance > node2.distance)
            return 1;
        return 0;
    }
}



public class dijkstraDirected {

    public static void main(String[] args){

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        ArrayList<ArrayList<Nodes>> adj = new ArrayList<>();

        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<Nodes>());
        }

        for(int i=0;i<m;i++)
        {
            int u = scn.nextInt();
            int v = scn.nextInt();
            int x = scn.nextInt();

            adj.get(u).add(new Nodes(x,v));
//            adj.get(v).add(new Node(x,u));
        }

        int[] ans = new int[n];
        for(int i=0;i< ans.length;i++)
            ans[i] = Integer.MAX_VALUE;

        Dijkstra(0,adj,ans);

        for(int i=0;i< ans.length;i++)
        {
            System.out.printf(ans[i] + " ");
        }
    }

    private static void Dijkstra(int source, ArrayList<ArrayList<Nodes>> adj, int[] ans) {

        PriorityQueue<Nodes> pq = new PriorityQueue<>(ans.length,new Nodes());
        pq.add(new Nodes(0,source));
        ans[source] = 0;

        while(!pq.isEmpty()){

            Nodes temp = pq.poll();

            int node = temp.getWeight();
            int dist = temp.getDistance();

            for(Nodes itr: adj.get(node))
            {
                if(dist + itr.getDistance() < ans[itr.getWeight()]) {
                    ans[itr.getWeight()] = dist + itr.getDistance();
                    pq.add(new Nodes(ans[itr.getWeight()],itr.getWeight()));
                }
            }
        }

    }
}
