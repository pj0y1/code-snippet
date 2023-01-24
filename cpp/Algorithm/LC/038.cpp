class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(n > 1){
            string tmp;
            int i = 0, j = 1;
            for(; j < ans.size(); j++){
                if (ans[i] != ans[j]){
                    tmp += '0'+j-i;
                    tmp += ans[i];
                    i = j;
                }
            }
            tmp += '0' + j-i;
            tmp += ans[i];
            ans = tmp;
            n -= 1;
        }
        return ans;
    }
};
