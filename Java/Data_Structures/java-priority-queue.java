// priority queue essentially stays sorted on insertion, ties are arbitrary

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//////////////////////////////////////////////////
// MY CODE START

import java.util.Comparator;
import java.util.PriorityQueue;

class Student {
    private int id;
    private String name;
    private double cgpa;
    
    public Student(int id, String name, double cgpa)
    {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }
    
    public int getID() { return id; }
    
    public String getName() { return name; }
    
    public double getCGPA() { return cgpa; }
    
    @Override
    public String toString()
    {
        return "(" + cgpa + ", " + name + ", " + id + ")";
    }
}

class Priorities implements Comparator<Student>{
    
    @Override
    public int compare(Student a, Student b)
    {
        if(a.getCGPA()!=b.getCGPA())
            return a.getCGPA()>b.getCGPA()?-1:1;
        if(!(a.getName().equals(b.getName())))
            return a.getName().compareTo(b.getName());
        else
            return Integer.compare(a.getID(),b.getID());        
    }
    
    public List<Student> getStudents(List<String> events)
    {
        PriorityQueue<Student> priors = new PriorityQueue<>(events.size(),this);
        
        for(String event : events)
        {
            if(event.equals("SERVED"))
                priors.poll();
            else
            {
                // event ENTER
                String[] fields = event.split("\\s+");
                Student newStudent = new Student(Integer.parseInt(fields[3]),fields[1],Double.parseDouble(fields[2]));
                priors.add(newStudent);
            }
        }
        
        // there isn't an ordered way to iterate through a priority queue
        List<Student> remaining = new ArrayList<>(priors.size());
        while(!priors.isEmpty())
            remaining.add(priors.poll());
        return remaining;
    }
}

// MY CODE END
//////////////////////////////////////////////////

public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}