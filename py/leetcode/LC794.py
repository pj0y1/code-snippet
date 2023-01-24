result = []

def gen(vec, i):
    if i == 9:
        result.append(''.join(vec))
        return
    for c in (' ', 'O', 'X'):
        vec[i] = c
        gen(vec, i+1)


def main():
    vec = ['' for _ in range(9)]
    gen(vec, 0)


if __name__ == '__main__':
    main()
    f = open("LC794_testcase", 'w')
    for s in result:
        # l = [s[0:3], s[3:6], s[6:]]
        print(f'["{s[0:3]}", "{s[3:6]}", "{s[6:]}"]', file=f)
    f.close()
