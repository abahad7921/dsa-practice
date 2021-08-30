import javax.swing.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        String s = ")()()()";

        checkParenthesis(s);

    }
  
    public static void checkParenthesis(String s){

        Stack<Character> st = new Stack<>();

        for(char i=0;i<s.length();i++){
            if(s.charAt(i) == '('){
                st.push(s.charAt(i));
            }
            else
            {
               if(!st.empty())
               {
                   if(st.peek() == '(')
                       st.pop();
                   else
                       st.push(s.charAt(i));
               }
               else
                   st.push(s.charAt(i));
            }
        }

        if(st.isEmpty())
            System.out.println("yes the parenthesis are balanced");
        else
            System.out.println("nope the parenthesis are'nt balances");
    }


}
