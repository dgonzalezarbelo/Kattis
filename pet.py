ind, sum = 0, 0
for _ in range(5):
    a, b, c, d = map(int, input().split())
    if a + b + c + d > sum:
        ind = _ + 1
        sum = a + b + c + d
print(ind, sum)