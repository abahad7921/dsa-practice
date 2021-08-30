
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = scn.nextInt();
        }

        monotonicStackIncreasing(arr);

        monotonicStackDeccreasing(arr);

    }

    public static void monotonicStackIncreasing(int[] arr){
        //remove as many elements(preferably 0) to make an increasing order

        Stack<Integer> st = new Stack<>();

        for(int i=0;i<arr.length;i++){

            if(st.isEmpty())
                st.push(arr[i]);
            else
            {
                if(st.peek() <= arr[i])
                    st.push(arr[i]);
                else
                {
                    while(!st.isEmpty()){  //first make the space for the current element

                        if(st.peek() <= arr[i])
                            break;
                        else
                            st.pop();
                    }

                    st.push(arr[i]); //then push the element in its desired position
                }
            }
        }

        for(int i: st){
            System.out.printf(i + " ");
        }

        System.out.println();
    }

    public static void monotonicStackDeccreasing(int[] arr){

        //remove as many elements(preferably 0) to make an decreasing order

        Stack<Integer> st = new Stack<>();

        for(int i=0;i<arr.length;i++){

            if(st.isEmpty())
                st.push(arr[i]);
            else
            {
                if(st.peek() >= arr[i])
                    st.push(arr[i]);
                else
                {
                    while(!st.isEmpty()){  //first make the space for the current element

                        if(st.peek() >= arr[i])
                            break;
                        else
                            st.pop();
                    }

                    st.push(arr[i]); //then push the element in its desired position
                }
            }
        }

        for(int i: st){
            System.out.printf(i + " ");
        }
    }
}
