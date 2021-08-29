/*
      input = 1 5 4 3 2
      output = 1 2 3 4 5
*/

import java.util.*;

public class Main {

    public static void main(String[] args) {

            Scanner scn = new Scanner(System.in);

            int n = scn.nextInt();

            int[] arr = new int[n];

            for(int i=0;i<n;i++)
            {
                arr[i] = scn.nextInt();
            }


            cyclicSort(arr);

            for (int i: arr)
            {
                System.out.printf(i + " ");
            }


    }

    private static void cyclicSort(int[] arr) {

        int i=0;

        while(i < arr.length)
        {
            int correctPos = arr[i] - 1;

            if(arr[i] != arr[correctPos])
            {
                swap(arr,i,correctPos);
            }
            else
                i++;
        }
    }

    private static void swap(int[] arr, int i, int correctPos) {

        int temp = arr[i];
        arr[i] = arr[correctPos];
        arr[correctPos] = temp;
    }

}



