n, m = map(int, input().split())

ost = 0
for i in range(1, n + 1):
    ost = int(str(ost) + str(i)) % m

print(ost)