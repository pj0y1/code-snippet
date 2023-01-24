from typing import List

class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        result1 = self.nlargest(nums1,k)
        result2 = self.nlargest(nums2,k)
        res = []
        for i in range(len(result1)):
            if len(result2) > k-i:
                r = self.merge(result1[i], result2[k-i])
                res.append(r)
        v = max([''.join(map(str,l)) for l in res])
        return [int(d) for d in list(v)]

    def nlargest(self, l, k):
        rg = min(k, len(l))
        result = [[]]
        idx = 0
        turn = []
        search_area = None
        for i in range(rg):
            if idx >= len(l)-1:
                if search_area is None:
                    end = result[-1]
                    if len(end)==1:
                        sreach_area = slice(0, end[0][1])
                    else:
                        j = len(end-1)
                        while j > 0:
                            low = end[j-1][1]
                            high = end[j][1]
                            if high - low > 1:
                                sreach_area = slice(low+1,high)
                                break
                            j -= 1
                        if j==0:
                            search_area = slice(0, end[0][1])
                n = max(l[search_area])
                pos = l.index(n)
                turn.append((n,pos))
                result.append(sorted(turn, key=lambda t: t[1]))
                start, stop = search_area.start, search_area_stop
                if stop-pos > 1:
                    search_area = slice(pos+1, stop)
                elif pos-start > 1:
                    search_area = slice(start, pos)
                else:
                    search_area = None
            else:
                n = max(l[idx:])
                pos = l.index(n)
                turn.append((n,pos))
                ll = sorted(turn, key=lambda t: t[1])
                result.append(ll)
                idx = pos+1
        return result

    def merge(self, l1, l2):
        i1 = 0
        i2 = 0
        result = []
        while i1 < len(l1) and i2 < len(l2):
            a = l1[i1]
            b = l2[i2]
            if a < b:
                result.append(b)
                i2 += 1
            elif a > b:
                result.append(a)
                i1 += 1
            else: # a == b
                if i1 == len(l1)-1:
                    result.append(b)
                    i2 += 1
                elif i2 == len(l2)-1:
                    result.append(a)
                    i1 += 1
                else:
                    a_right = l1[i1+1]
                    b_right = l2[i2+1]
                    if a_right > a: # i.e also > b
                        result.append(a)
                        i1 += 1
                    elif b_right > b:
                        result.append(b)
                        i2 += 1
                    else:
                        result.append(a)
                        result.append(b)
                        i1 += 1
                        i2 += 1
        if i1 < len(l1):
            result.extend(l1[i1:])
        elif i2 < len(l2):
            result.extend(l2[i2:])
        return result


if __name__ == '__main__':
    result = Solution().merge([6,7],[6,0,4])
    print(result)
