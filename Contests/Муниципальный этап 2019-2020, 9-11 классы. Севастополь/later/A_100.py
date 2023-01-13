nums = input()

sum_controls = 0
sum_ratings = 0

i = 1
for n in nums:
    if(i % 7 == 0):
        sum_controls += int(n)
    sum_ratings += int(n)

    i += 1

round_controls = sum_controls / (len(nums) // 7)
round_ratings = sum_ratings / len(nums)

s = str(round_controls)
if(int(s[s.find('.') + 1]) >= 5):
    round_controls = int(round_controls) + 1    

s = str(round_ratings)
if(int(s[s.find('.') + 1]) >= 5):
    round_ratings = int(round_ratings) + 1 

print(int(min(round_controls, round_ratings)))