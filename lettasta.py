n = int(input())
m = int(input())
nombres = input().split()
v = [0] * n
for _ in range(m):
    ns = list(map(int, input().split()))
    for i in range(n):
        v[i] += ns[i]
maxi = max(v)
i = v.index(maxi)
print(nombres[i])