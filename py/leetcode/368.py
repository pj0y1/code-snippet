"""
368. 最大整除子集
"""
from typing import List 

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        s = sorted(nums)
        ans = []
        for n in s:
            tmp = set()
            find_asc = False
            for l in ans:
                idx = len(l)-1
                if n % l[idx] == 0:
                    l.append(n)
                    find_asc = True
                else:
                    while idx >= 0 and n % l[idx]:
                        idx -= 1
                    if idx >= 0:
                        k = l[:idx+1]
                        k.append(n)
                        tmp.add(tuple(k))
                        find_asc = True
            if not find_asc:
                # print("add single number", n)
                ans.append([n])
            # print("tmp", tmp)
            ans.extend([list(t) for t in tmp])
            # print("ans", ans)

        return max(ans, key=len)


if __name__ == '__main__':
    input = [135,929,66,772,768,846,815,967,888,90,771,793,68,978,994,609,368,36,927,360,187,305,887,874,28,337,139,207,798,386,412,284,666,478,56,434,675,222,752,562,311,875,706,378,852,52,987,219,439,913,931,626,218,169,499,597,505,989,803,303,726,567,586,392,44,993,177,70,214,280,983,876,154,688,254,357,91,240,928,882,504,858,507,73,26,669,530,698,472,184,423,38,122,814,433,466,342,502,680,622,484,907,775,523,160,132,966,751,411,847,607,268,705,679,293,61,348,174,758,171,358,533,208,479,992,944,40,493,975,661,328,787,850,393,270,144,13,102,947,717,780,591,778,127,765,297,474,856,952,469,199,247,508,691,574,520,370,807,306,220,551,46,399,147,906,115,496,244,405,612,483,54,85,253,909,388,721,460,580,150,560,99,872,718,757,684,828,314,290,226,812,195,693,738,43,288,143,654,770,196,739,375,456,126,95,915,464,27,417,23,125,92,881,730,712,916,25,206,836,179,926,146,420,152,588,890,962,774,367,408,41,831,786,457,205,911,96,649,59,384,616,571,719,101,848,217,919,267,506,233,819,7,327,578,47,509,364,855,714,302,362,120,830,914,145,837,216,937,432,844,151,429,759,185,594,823,39,659,800,692,372,521,444,449,251,945,628,512,559,943,413,401,445,829,203,6,640,465,585,287,541,595,438,232,104,409,805,889,863,638,613,421,352,667,741,545,131,243,481,783,75,366,563,709,810,820,448,343,642,338,528,188,854,454,843,48,324,106,750,664,790,579,15,941,468,646,198,340,191,867,130,981,407,279,260,648,948,695,797,898,69,422,687,999,436,980,647,862,467,859,821,9,65,950,471,792,620,83,93,382,485,241,781,568,156,237,515,486,335,746,902,636,87,725,427,540,701,744,326,884,192,410,88,566,291,827,21,696,312,707,794,565,880,289,121,938,447,441,390,802,548,826,743,629,643,897,940,917,623,317,12,985,949,431,516,924,81,14,166,117,908,886,227,72,224,4,53,363,389,315,278,331,20,295,263,603,500,631,723,78,745,133,111,304,518,892,361,200,526,262,353,930,544,162,395,34,374,611,547,118,749,990,602,452,605,969,149,965,24,193,710,596,871,242,630,57,711,3,19,257,767,598,50,330,538,920,114,782,921,658,491,883,769,885,140,708,258,277,414,175,252,851,997,839,546,320,322,16,811,1,834,955,8,2,662,259,939,747,64,517,406,606,385,211,753,683,440,33,273,618,632,558,610,670,63,213,576,554,333,341,655,671,238,97,501,74,956,964,865,527,234,492,809,45,141,489,482,495,742,158,339,197,430,590,250,510,564,419,754,256,645,841,103,29,737,212,381,77,561,979,766,308,573,136,42,31,264,653,644,895,639,105,785,842,960,170,298,301,537,455,18,319,942,124,961,321,394,732,896,756,428,722,228,593,183,534,731,736,134,164,860,748,176]
    ans = Solution().largestDivisibleSubset(input)
    print(ans)