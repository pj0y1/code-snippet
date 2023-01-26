#!/usr/bin/env python3
''' add 2 binary numbers and return in binary form'''

import sys, re, functools, itertools

if __name__ == "__main__":
#    print(sys.argv)
    pattern = re.compile('^0b[01]+$')
    if len(sys.argv) == 3 and pattern.match(sys.argv[1]) and pattern.match(sys.argv[2]):
        a = int(sys.argv[1], base=2)
        b = int(sys.argv[2], base=2)

        print(bin(a+b))

        a = [int(c) for c in sys.argv[1][:1:-1]]
        b = [int(c) for c in sys.argv[2][:1:-1]]

        if len(a) < len(b):
            a += [0]*(len(b)-len(a))
        else:
            b += [0]*(len(a)-len(b))

        def bitwise_add(i, v, l):
            s = i+v[0]+v[1]
            l.append(s%2)
            return s//2

        c = []
        bitwise_add2c = functools.partial(bitwise_add, l=c)
        initial_carry_bit = 0
        final_carry_bit = functools.reduce(bitwise_add2c, zip(a,b), initial_carry_bit)
        if final_carry_bit:
            c.append(final_carry_bit)
        
        c.reverse()
        result = functools.reduce(lambda x,y: x*2+y, c, 0)
        print(bin(result))
