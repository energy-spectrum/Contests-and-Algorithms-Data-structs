n = int(input())

klasters = [set()]
serversToKlasters = dict()

for i in range(n):
    a, b = map(int, input().split())

    meybeA = serversToKlasters.get(a, -1)
    meybeB = serversToKlasters.get(b, -1)

    if meybeA != -1:
        klasters[meybeA].add(b)
        serversToKlasters[b] = meybeA
    elif meybeB != -1:
        klasters[meybeB].add(a)
        serversToKlasters[a] = meybeB
    else:
        klasters.append({a, b})
        serversToKlasters[a] = len(klasters) - 1
        serversToKlasters[b] = len(klasters) - 1

res = []

q = int(input())
for i in range(q):
    x, k = map(int, input().split())

    res.append([])

    idxKlaster = serversToKlasters[x]

    for j in input().split():
        idServer = int(j)

        if idServer in klasters[idxKlaster]:
            res[len(res) - 1].append(idServer)

for i in range(len(res)):
    n = len(res[i])
    print(n, end=' ')
    
    for j in range(n):
        print(res[i][j], end=' ')
    print()
