def numDecodings(s: str) -> int:
    if s[0] == '0':
        return 0
    seg = []
    start = 0
    n = len(s)
    while start < n:
        pos = s.find('0', start)
        if pos == -1:
            seg.append(s[start:])
            break
        if s[pos-1] in ('1', '2'):
            if pos-1 > start:
                seg.append(s[start:pos-1])
            start = pos+1
        else:
            return 0
    m = len(seg)
    i = 0
    while i < m:
        a = seg.pop(0)
        print(a)
        if len(a) < 2:
            seg.append(a)
            i += 1
            continue
        tmp = []
        t = 0
        start = 0
        while t < len(a)-1:
            if int(a[t:t+2]) > 26:
                tmp.append(t+1)
            t += 1
        prev = 0
        for k in tmp:
            seg.append(a[prev:k])
            prev = k
        seg.append(a[prev:])
        i += 1
    c = calc()
    prod = 1
    for p in seg:
        r = c(p)
        if r == 0:
            return 0
        prod *= r
    return prod

def calc():
    cache = [0, 1, 2, 3]
    def f(s):
        n = len(s)
        if n <= len(cache):
            return cache[n]
        while len(cache) < n:
            m = cache[-1] + cache[-2] - 1
            cache.append(m)
        return cache[n]
    return f




if __name__ == '__main__':
    ans = numDecodings("12013710479")
    print(ans)
    for _ in range(100):
        print(2, sep='', end='')
    print('\n')