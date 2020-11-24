import java.util.*;

public class Main {
    static int binary_search(Integer[] arr, int tar){
        int start = 0, end = arr.length-1;
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(arr[mid]==tar)
                return mid;
            else if (arr[mid]<tar)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    static int upper_bound(Integer[] arr, int tar){
        int start = 0, end = arr.length;
        int mid;
        while(start<end){
            mid = (start+end)/2;
            if(arr[mid]<=tar)
                start = mid+1;
            else
                end = mid;
        }
        return start;
    }
    static int lower_bound(Integer[] arr, int tar){
        int start = 0, end = arr.length;
        int mid;
        while(start<end){
            mid = (start+end)/2;
            if(arr[mid]<tar)
                start = mid+1;
            else
                end = mid;
        }
        return start;
    }

    public static void main(String[] args) {
        Integer[] arr = new Integer[] {1,1,3,3,5,5,7,7,7,7,9,9};
//        Arrays.sort(arr, Collections.reverseOrder());
        System.out.println(binary_search(arr, 3));
        System.out.println(binary_search(arr, 13));
        System.out.println(upper_bound(arr, 7));
        System.out.println(lower_bound(arr ,7));
        System.out.println(upper_bound(arr, 0));
        System.out.println(lower_bound(arr ,0));
        System.out.println(upper_bound(arr, 13));
        System.out.println(lower_bound(arr ,13));

    }
}
