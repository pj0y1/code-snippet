line = input()
low, high = line.split()
low = int(low)
high = int(high)

primes = [2,3,5,7]
n = primes[-1]+1
while n <= high:
    is_prime = True
    for p in primes:
    	if n % p == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(n)
    n += 1
    
for p in primes:
    if low <= p <= high:
        print(p)
