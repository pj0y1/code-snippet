
def main():
    r = []
    for i in range(13):
        if i & 1: 
            t = [2*j for j in range(2**i, 0, -1)]
        else:
            t = [2*j+1 for j in range(2**i)]
        r.extend(t)

    print(r)


if __name__ == '__main__':
    main()
