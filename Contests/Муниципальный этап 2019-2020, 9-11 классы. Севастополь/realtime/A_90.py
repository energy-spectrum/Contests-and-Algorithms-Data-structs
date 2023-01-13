s = input()
c = 1
w = 0
cw = 0
t = 0
for i in s:
    if c % 7 == 0:
        w += int(i)
        cw += 1
    t += int(i)
    c += 1
a=round(t / c)
if a < round(w / cw):
    print(a)
else:
    print(round(w / cw))