"""slightly fancier list comprehension stuff"""

if __name__ == '__main__':
    #read inputs into list of names and scores
    data = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        data.append([name,score])
    #build a list of scores for getting the second lowest
    scores = [item[1] for item in data]
    second_lowest = sorted(list(set(scores)))[1]
    #put names of students with score equal to second lowest in a separate list
    names = [item[0] for item in data if item[1]==second_lowest]
    #sort and print the names
    names.sort()
    for name in names:
        print(name)
