
t = input()
for i in range(t):
  [n, p] = raw_input().split(" ")
  n = int(n)
  p = int(p)
  plist = []
  for j in range(p):
     plist.append(raw_input())
  plist.sort(key = lambda x: len(x))
  left = 0
  right = len(plist) - 1
  while left < len(plist) -1:
    while left < right:
      if plist[right].startswith(plist[left]):
        plist.pop(right)
      right -= 1
    left += 1
    right = len(plist) - 1
  count = 2 ** n
  for k in plist:
    count -= 2** (n - len(k))
  print "Case #{}: {}".format(i+1, count)
