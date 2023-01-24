import math
line = input()
low, high = line.split()
low = int(low)
high = int(high)

primes = [2,3,5,7]
n = 11

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

u = int(u)+1
while u <= high:
    is_prime = True
    for p in primes:
        if u%p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(u)
        print("append", u)
    u += 1

exist = False
for p in primes:
    if low <= p <= high:
        exist = True
        print(p)
if not exist:
    print(0)
