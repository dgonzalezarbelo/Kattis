c = float(input())
l = int(input())
s = 0.0
for _ in range(l):
    a, b = map(float, input().split())
    s += a * b * c
print(s)