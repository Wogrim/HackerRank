"""namedtuple lets you get tuple fields by name, not just index"""

from collections import namedtuple

n = int(input())
column_names = input().split()
Student = namedtuple("Student",column_names)
students = []
for _ in range(n):
    students.append(Student(*input().split()))
total = 0
for stu in students:
    total += int(stu.MARKS)
print("{0:.2f}".format(total/n))
