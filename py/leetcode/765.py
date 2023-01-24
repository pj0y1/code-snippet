# min swap couples

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        i = 0
        l = []
        while i < len(row)-1:
            v = row[i]
            o = self.other(v)
            if row[i+1] == o:
                i += 2
            else:
                l.append(v)
                i += 1

        depth_count = 0
        q = []
        while True:
            a = l[0]
            e = l[1]
            b = self.other(a)
            pos = l.index(b)
            if pos > 0:
                q.append(l[pos-1])
            if pos < len(l)-1:
                q.append(l[pos+1])


class Node:

    def __init(v, left, right):
        self.val = v
        self.left = left
        self.right = right
        
def other(v):
    return v-1 if v%2 else v+1


def find_loop(l):
    v = l.pop(0)
    pos = {}
    for i,n in enumerate(l):
        pos[n] = i

    o = other(v)
    p = pos[o]
    q = []
    while p != 0:
        q.append(p-1)
        if p < len(l)-1:
            q.append(p
