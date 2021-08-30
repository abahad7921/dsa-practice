import java.util.*;

public class Main {

    public static void main(String[] args) {

       Scanner scn = new Scanner(System.in);

       int n = scn.nextInt();
       int[] arr = new int[n];

       for(int i=0;i<n;i++){
           arr[i] = scn.nextInt();
       }

       findMin(arr);
    }

    public static void findMin(int[] arr){

        //find the minimum element till the current element

        Stack<Integer> st = new Stack<>();
        int n = arr.length;

        for(int i=0;i<n;i++){

            if(st.isEmpty())
                st.push(arr[i]);
            else
            {
                if(st.peek() > arr[i])
                {
                    st.push(arr[i]);
                }
            }
        }

        for(int i=n-1;i>=0;i--){

            System.out.println("for index till "+ i +"  element = "+ arr[i] + " element smallest is " + st.peek());

            if(arr[i] == st.peek()){
                st.pop();
            }
        }
    }
