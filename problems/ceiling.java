/*
      Find the ceiling of a given number in a sorted array of integeres
      
      input: 1,2,5,6,7,8,9,15,22
             10
      output: 15
*/


public class Main {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int[] arr = {1,2,5,6,7,8,9,15,22};

        int target = scn.nextInt();
        System.out.println(arr[findCeiling(arr,target)]);

        System.out.println(arr[findFloor(arr,target)]);

    }

    static int findCeiling(int[] arr,int target)
    {
        int start =0,end = arr.length -1,mid = -1;

        if(target > arr[end])
            return -1;

        while(start <= end)
        {
            mid = start + (end - start)/2;

            if(arr[mid] == target)
                return mid;
            else if(arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return start;
    }
}
