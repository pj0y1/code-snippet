class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> tmp;
        int carry = 1, n;
        for(int i = digits.size()-1; i >= 0 || carry > 0; i--){
            if (i >= 0){
                n = digits[i];
            } else {
                n = 0;
            }
            n += carry;
            carry = n/10;
            tmp.push(n%10);
        }
        vector<int> ans;
        while(!tmp.empty()){
            ans.push_back(tmp.top());
            tmp.pop();
        }
        return ans;
    }
};
