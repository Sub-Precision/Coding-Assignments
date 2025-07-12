def knapsack(W, wt, val, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    selected_items = []

    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]

    # backtrack to find selected items
    i, w = n, W
    while i > 0 and w > 0:
        if K[i][w] != K[i-1][w]:
            selected_items.append(i-1)
            w -= wt[i-1]
        i -= 1

    return K[n][W], selected_items


def main():
    # loading stock table
    weights = [90, 1500, 150, 800, 40, 290, 160, 380, 25, 90]
    returnRate = [0.1, 0.2, 0.12, 0.15, 0.08, 0.09, 0.18, 0.25, 0.11, 0.06]
    names = ["APL", "AMZ", "FBI", "GOLG", "IBN", "MAFT", "MDNA", "TSL", "VO", "WLMT"]
    # creating empty list to create values
    values = []
    # multiply corresponding weights and return rate to get the expected return of individual stocks
    for i in range(len(returnRate)):
        values.append(weights[i] * returnRate[i])
    # taking user input for budget
    max_weight = int(input("Enter your maximum budget:"))
    portfolio = []
    # calling 0/1 knapsack algorithm
    nums, selected = knapsack(max_weight, weights, values, len(weights))
    # finding the names of the selected stocks
    for i in range(len(selected)):
        portfolio.append(names[selected[i]])
    # printing results
    print("List of chosen stocks:", portfolio)
    print("Expected Return on investment:", nums)

main()
