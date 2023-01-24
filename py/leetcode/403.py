memo = {}

class Solution:
    def checkSteps(self, steps, k) -> bool:
        if memo.get((steps, k)) is not None:
            return memo.get((steps, k))
        if not steps:
            return True
        i = 0
        s = 0
        nka, nk, nkb = None, None, None
        while i < len(steps):
            s += steps[i]
            if s == k-1:
                nka = i 
            elif s == k:
                nk = i 
            elif s == k+1:
                nkb = i 
            i += 1
        rka, rk, rkb = False, False, False 
        if nka is not None:
            rka = self.checkSteps(tuple(steps[nka+1:]), k-1)
        if nk is not None:
            rk = self.checkSteps(tuple(steps[nk+1:]), k)
        if nkb is not None:
            rkb = self.checkSteps(tuple(steps[nkb+1:]), k+1)
        memo[(steps, k)] = rka or rk or rkb
        return rka or rk or rkb


    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        steps = [stones[i]-stones[i-1] for i in range(1, n)]
        return self.checkSteps(tuple(steps[1:]), 1)
