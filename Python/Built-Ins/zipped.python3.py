"""zip() combines separate iterables into a list of tuples"""

n, x = map(int,input().split())
subjects = []
for _ in range(x):
    subject = map(float,input().split())
    subjects.append(subject)
for student in zip(*subjects):
    print(format(sum(student)/x,".1f"))
