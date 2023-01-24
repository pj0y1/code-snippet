import math

line = input()
low, high = line.split()
low = int(low)
high = int(high)

primes = [2,3,5,7]
n = 11

s = {n for n in range(low, high+1)}
u = math.sqrt(high)
while n <= u:
    is_prime = True
    for p in primes:
        if n%p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(n)
    n += 1

for p in primes:
    m = 2
    while m*p <= high:
        s.discard(m*p)
        m += 1
        
l = list(s)
l.sort()
hit = False
for i in l:
    if low <= i <= high:
        print(i)
        hit = True
if not hit:
    print(0)

