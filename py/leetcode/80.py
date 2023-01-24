from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return n
        i = 0
        j = 1
        repeat = 0
        while j < n:
            if nums[i] == nums[j]:
                repeat += 1
            else:
                if repeat >= 1:
                    nums[i+1] = nums[i]
                    i += 2
                    nums[i] = nums[j]
                    repeat = 0
                else:
                    i += 1
                    nums[i] = nums[j]
            j += 1
        print("repeat", repeat)
        if repeat >= 1:
            nums[i+1] = nums[i]
            ans = i+2
        else:
            ans = i+1
        print(nums[:ans])
        return ans


if __name__ == "__main__":
    s = Solution()
    testcases = [
        [1,1,1,2,2,3],
        [0,0,1,1,1,1,2,3,3],
        [-1, 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,5,5,6],
    ]

    for c in testcases:
        s.removeDuplicates(c)