class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        ans.push_back({1});
        int i = 1;
        while (i < numRows){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j=1; j < ans[i-1].size(); j++){
                tmp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
            i += 1;
        }
        return ans;
    }
};
