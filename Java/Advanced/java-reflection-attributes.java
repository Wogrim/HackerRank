// we can get a class's declared methods

// hidden Student class here

public class Solution {

    private static class MethodComp implements Comparator<Method> {
        @Override
        public int compare(Method a, Method b)
        {
            return a.getName().compareTo(b.getName());
        }
    }

    public static void main(String[] args){
        // get the methods of the Student class
        Class student = Student.class;
        Method[] methods = student.getDeclaredMethods();
        
        // sort them by name
        Arrays.sort(methods, new MethodComp());

        //print the names
        for(Method method: methods){
            System.out.println(method.getName());
        }
    }
}
