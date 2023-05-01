// generic function which prints an array of anything

public class Solution {

    private static <T> void printArray(T[] list)
    {
        for(T item : list)
            System.out.println(item);
    }

    public static void main(String[] args) {
        Integer[] numbers = {1,2,3};
        String[] words = {"Hello","World"};
        printArray(numbers);
        printArray(words);
    }
}
