class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        // 利用了异或的性质 a^a = 0 a^b = b^a a^0=a
        for(int i = 1; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
