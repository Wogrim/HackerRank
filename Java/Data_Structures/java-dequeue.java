// this problem isn't very efficient with a dequeue so didn't use it

import java.util.*;
public class test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		//put all nums in array
		int[] nums = new int[n];
		for(int i = 0; i < n; i++)
			nums[i] = in.nextInt();
		
		HashMap<Integer,Integer> window = new HashMap<>();

		//make the starting window
		for (int i = 0; i < m; i++) {
			int num = nums[i];
			Integer current = window.putIfAbsent(num,1);
			if(current!=null)
				window.put(num,current+1);
		}
		
		int max = window.size();
		
		//slide the window, removing and adding one num at a time
		for (int i = 0, j = m; j < n; i++, j++)
		{
			//add
			int num = nums[j];
			Integer current = window.putIfAbsent(num,1);
			if(current!=null)
				window.put(num,current+1);
				
			//remove
			int remove = nums[i];
			current = window.get(remove);
			if(current==1)
				window.remove(remove);
			else
				window.put(remove,current-1);
			
			//update max
			if(window.size()>max)
				max = window.size();
		}
		
		System.out.println(max);
	}
}
