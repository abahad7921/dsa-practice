package graph;

//this is the inefficient implementation of the Prim's Algorithm

import java.util.ArrayList;
class node{
    private int distance,vertex;

    node(){}

    node(int vertex,int distance)
    {
        this.distance = distance;
        this.vertex = vertex;
    }

    int getDistance()
    {
        return this.distance;
    }

    int getVertex(){
        return this.vertex;
    }
}

class prims{

    public static void main(String[] args){

        int n = 5;
        ArrayList<ArrayList<node> > adj = new ArrayList<ArrayList<node> >();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<node>());

        adj.get(0).add(new node(1, 2));
        adj.get(1).add(new node(0, 2));

        adj.get(1).add(new node(2, 3));
        adj.get(2).add(new node(1, 3));

        adj.get(0).add(new node(3, 6));
        adj.get(3).add(new node(0, 6));

        adj.get(1).add(new node(3, 8));
        adj.get(3).add(new node(1, 8));

        adj.get(1).add(new node(4, 5));
        adj.get(4).add(new node(1, 5));

        adj.get(2).add(new node(4, 7));
        adj.get(4).add(new node(2, 7));

        primsAlgo(adj,n);
    }

    private static void primsAlgo(ArrayList<ArrayList<node> > adj, int n) {

        int[] key = new int[n];
        int[] parent = new int[n];
        boolean[] mst = new boolean[n];

        for (int i = 0; i < n; i++) {
            key[i] = Integer.MAX_VALUE;
            mst[i] = false;
            parent[i] = -1;
        }

        key[0] = 0;

        for (int i = 0; i < n - 1; i++) { //since there are n - 1 edges in minimum spanning tree

            int min = Integer.MAX_VALUE;
            int u = 0;
            for (int j = 0; j < n; j++) {

                if (mst[j] == false && key[j] < min) {
                    min = key[j];
                    u = j;
                }
            }

            for (node itr : adj.get(u)) {
                int vertex = itr.getVertex();
                int distance = itr.getDistance();

                if (mst[vertex] == false && distance < key[vertex]) {
                    key[vertex] = distance;
                    parent[vertex] = u;
                }
            }

            mst[u] = true;
        }


        for(int i: parent)
        {
            System.out.printf(i + " ");
        }
    }
}
