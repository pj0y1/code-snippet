class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            s = max(nums[i], s+nums[i]);
            ans = max(ans, s);
        }
        return ans;   
    }
};
