// sorting a List with lambda comparison function

import java.util.*;

class Student{
	private int id;
	private String fname;
	private double cgpa;
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getId() {
		return id;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
}

public class Solution
{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		
		List<Student> studentList = new ArrayList<Student>();
		while(testCases>0){
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();
			
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			
			testCases--;
		}
        
        in.close();
        
        studentList.sort((Student a, Student b)-> {
            //sort by CGPA descending
            if(a.getCgpa()!=b.getCgpa())
                return b.getCgpa()>a.getCgpa()?1:-1;
            //sort by first name ascending
            if(!a.getFname().equals(b.getFname()))
                return a.getFname().compareTo(b.getFname());
            //sort by ID ascending
            return a.getId()-b.getId();
        });
      
      	for(Student st: studentList){
			System.out.println(st.getFname());
		}
	}
}
