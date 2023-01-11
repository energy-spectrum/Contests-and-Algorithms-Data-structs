j = input()
s = input()

ans = 0
for c in set(j):
    ans += s.count(c)

print(ans)
