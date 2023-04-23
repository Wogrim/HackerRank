"""some dumb game with scoring words based on vowels"""

def minion_game(string):
    # for each consonant/vowel in the string, 
    # the next i letters are a word if not past the string length
    # in other words you get points for the distance from the end of the string
    S_points = 0
    K_points = 0
    n = len(string)
    vowels = "AEIOU"
    for i in range(n):
        points = n-i
        # check if this letter is a vowel
        if string[i] in vowels:
            K_points += points
        else:
            S_points += points
    if K_points > S_points:
        print("Kevin " + str(K_points))
    elif S_points > K_points:
        print("Stuart " + str(S_points))
    else:
        print("Draw")
    return
