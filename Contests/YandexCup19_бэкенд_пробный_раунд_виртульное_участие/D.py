from sys import stdout


n = int(input())

l = 1
r = n

while l != r:
    mid = (l + r) // 2

    print(mid)
    stdout.flush()

    req = int(input())

    if (req == 1):
        l = mid + 1
    else:
        r = mid
    
print('! ' + str(r))
