n = int(input())
balls = 1
maxBalls = 1

for i in range(2, n + 1):
    balls += i
    if balls > n:
        break
    sqrtBalls = balls**(1/2)
    if int(sqrtBalls) == sqrtBalls:
        maxBalls = balls
print(maxBalls)