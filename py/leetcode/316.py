def removeDuplicateLetters(s: str) -> str:
        dd = {}
        for i, c in enumerate(s):
            dd.setdefault(c, []).append(i)

        ll = []
        for i, c in enumerate(s):
            if c not in ll:
                ll.append(c)
            else:
                pos = ll.index(c)
                if pos == len(ll)-1:
                    pass
                else:
                    ok = True
                    for cc in ll[pos+1:]:
                        if cc > c and dd[cc][-1] < i:
                            ok = False
                            break
                    if ok:
                        ll.pop(pos)
                        ll.append(c)
            print(ll)
        return ''.join(ll)

if __name__ == '__main__':
    ans = removeDuplicateLetters("rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws")
    print(ans)
