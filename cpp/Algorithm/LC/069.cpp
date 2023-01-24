class Solution {
public:
    int mySqrt(int x) {
        // 二分答案11110000类型
        long long l = 0, r = x;
        while(l != r){
            long long mid = (l+r+1)/2;
            if(mid*mid > x){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        return l;
    }
};
