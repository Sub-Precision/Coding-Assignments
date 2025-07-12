import re
from collections import Counter


def edit_distance(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(m + 1):
        dp[i][0] = i
    
    for j in range(n + 1):
        dp[0][j] = j
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    
    return dp[m][n]

def spell_check(word, dictionary):
    min_distance = float('inf')
    suggested_word = None
    
    for w in dictionary:
        distance = edit_distance(word, w)
        if distance < min_distance:
            min_distance = distance
            suggested_word = w
    
    return suggested_word

def main():
    dictionary = []
    misspelled = []
    with open("dictionary.txt") as outfile:
        for line in outfile:
            for words in line:
                # putting all lines of text into one continuous list
                dictionary.append(words)
    dictionary = ''.join([str(newString) for newString in dictionary])
    # formatting to all lowercase and removing \n to avoid complications
    dictionary = dictionary.lower()
    dictionary = dictionary.strip()
    # this line i also found was discovered in techiedelight.com, modified for my program
    s = re.sub('[,,.]', '', dictionary)
    dictionary = s
    dictionaryArray = dictionary.split()
    counts = Counter(dictionaryArray)

    print("Dictionary size:", len(counts))
    userInput = input("Please enter the file to check for spelling:")

    with open(userInput) as outfile:
        for line in outfile:
            for words in line:
                # putting all lines of text into one continuous list
                misspelled.append(words)
    misspelled = ''.join([str(newString) for newString in misspelled])
    # formatting to all lowercase and removing \n to avoid complications
    misspelled = misspelled.lower()
    misspelled = misspelled.strip()
    # this line i also found was discovered in techiedelight.com, modified for my program
    s = re.sub('[,,.]', '', misspelled)
    misspelled = s
    misspelledArray = misspelled.split()


    for i in range(len(misspelledArray)):
        suggestions = spell_check(misspelledArray[i], counts)
        print(suggestions)


main()
