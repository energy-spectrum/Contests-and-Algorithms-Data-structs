n, m = map(int, input().split())
l = [input().split() for i in range(m)]

k = [False for i in range(n)]
p = 0
for i in l:
    if i[0] == '1':
        p = 0
        c = k[:]
        for j in range(int(i[1]) - 1, -1, -1):
            
            k[p] = not c[j]
            p += 1

    else:
        print(int(k[int(i[1]) - 1]))