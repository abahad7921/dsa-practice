/*
    input: n m (n is the number of notes, m is the no. of edges)
           following n lines follow u & v (there is an edge between u and v)

*/



package com.company;

import javax.swing.*;
import javax.xml.transform.sax.SAXTransformerFactory;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        //Graph reprsentation using integer array Space: O(n*n)
        int[][] adjecencyList = new int[n+1][n+1];

        for(int i=0;i<adjecencyList.length;i++){
            for(int j=0;j<adjecencyList[i].length;j++){
                adjecencyList[i][j] = 0;//initialise all the elements to 0
            }
        }

        for(int i=0;i<m;i++){
            int u = scn.nextInt();
            int v = scn.nextInt();

            adjecencyList[u][v] = 1;
            adjecencyList[v][u] = 1;
        }

        for(int i=0;i<adjecencyList.length;i++){
            System.out.println(Arrays.toString(adjecencyList[i]));
        }

        //Graph representation using ArrayList (Space O(n + 2*m))

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

        for(int i=0;i< adj.size();i++){
            System.out.println(adj.get(i));
        }
    }


}
