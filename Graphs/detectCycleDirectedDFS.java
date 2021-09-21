import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int nodes = scn.nextInt();
        int edges = scn.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<=nodes;i++){
            adj.add(new ArrayList<Integer>());
        }

        //detect cycle in a directed graph using DFS
        for(int i=0;i<edges;i++){
            int u = scn.nextInt();
            int v = scn.nextInt();

            adj.get(u).add(v);
        }

        int[] visited = new int[nodes + 1];
        int[] dfsvisited = new int[nodes + 1];

        int i=1;
        for(;i<=nodes;i++){
            if(visited[i] == 0){
                if(detectCycleDirectedDFS(i,adj,visited,dfsvisited) == true)
                {
                    System.out.println("yes this graph contains a cycle");
                    break;
                }
            }
        }

        if(i > nodes){
            System.out.println("nope there aint no cycle in the graph");
        }


    }

    public static boolean detectCycleDirectedDFS(int node,ArrayList<ArrayList<Integer>> adj,int[] visited,int[] dfsVisited){

        visited[node] = 1;
        dfsVisited[node] = 1;

        for(int itr : adj.get(node)){

            if(visited[itr] == 0){
                if(detectCycleDirectedDFS(itr,adj,visited,dfsVisited) == true)
                    return true;

            }
            else if(dfsVisited[itr] == 1)
                return true;
        }

        dfsVisited[node] = 0;
        return false;
    }
}


}
