def checkAnagrams(string1, string2):
    # put characters of strings into arrays
    stringArray1 = list(string1)
    stringArray2 = list(string2)
    # get length of characters in input for loops
    stringLength1 = len(stringArray1)
    stringLength2 = len(stringArray2)
    # setting up counter variable to test matched characters
    counter = 0
    # quick evaluation to see if strings are same size
    if stringLength1 != stringLength2:
        return False
    else:
        # evaluating strings with nested for loops
        for x in range(stringLength1):
            for y in range(stringLength2):
                if stringArray1[x] == stringArray2[y]:
                    counter += 1
                    break
                else:
                    continue
        if counter == stringLength1:
            return True
        else:
            return False

def main():
    # getting information from user
    # i went with this format because an anagram can use a phrase, sample output cannot use phrases
    string1 = input("Input a string: ")
    string2 = input("Input a second string: ")
    # quick evaluation to see if strings are same size
    result = checkAnagrams(string1, string2)
    if result == True:
        print(string1, "is an Anagram of", string2)
    else:
        print(string1, "is not an Anagram of", string2)

main()