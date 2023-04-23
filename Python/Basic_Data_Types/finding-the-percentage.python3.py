"""float precision formatting"""

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        #line is a list of the subsequent scores (in string form)
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    marks = student_marks[query_name]
    avg = sum(marks)/len(marks)
    print("{0:.2f}".format(avg))
