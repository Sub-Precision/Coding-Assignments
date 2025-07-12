def main():
    with open("Country.csv") as outfile:
        for line in outfile:
            finalArray = []
            #line = line.replace("'", "")
            finalArray.extend(line.split(','))
            finalArray[1].replace("'", "")
            finalArray[2].replace("'", "")
            #finalArray[6].replace("'", "")
            #finalArray[10].replace("'", "")
            print("INSERT INTO COUNTRY VALUES")
            print("\t(", finalArray[0], ",", finalArray[1], ",", finalArray[2], ",", finalArray[3], ");")

main()
