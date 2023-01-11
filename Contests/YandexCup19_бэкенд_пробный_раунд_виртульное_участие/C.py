k, n = map(int, input().split())

l = [int(i) for i in input().split()]

numV, numP = 0, 0
for i in range(n):
    if l[i] % 3 == 0 and l[i] % 5 == 0:
        continue

    if l[i] % 5 == 0:
        numV += 1
    elif l[i] % 3 == 0:
        numP += 1

    if numV == k or numP == k:
        if numV > numP:
            print("Vasya")
        elif numV == numP:
            print("Draw")
        else:
            print("Petya")

        break
else:
    if numV > numP:
        print("Vasya")
    elif numV == numP:
        print("Draw")
    else:
        print("Petya")
