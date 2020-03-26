t = int(input())
for i in range(0, t):
  m, n = map(int, input().split()) 
  a = list(map(int, input().split()))
  p = list(map(int, input().split()))
  if (len(a) - len(p) == 1):
    print("YES")
    w = -1
  else:
    w = 1
  while (w > 0):
    w = 0
    for x in p:
      if a[x-1] > a[x]:
        w += 1
        a[x-1], a[x] = a[x], a[x-1]
  if (a == sorted(a) and w >= 0):
    print("YES")
  elif (w >= 0):
    print("NO")