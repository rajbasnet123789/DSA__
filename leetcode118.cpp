class Solution {
public:
    vector<int> rec_(int i) {
        vector<int> ans;
        ans.push_back(1);
        long long val = 1;

        for (int k = 1; k < i; k++) {
            val = val * (i - k) / k;
            ans.push_back((int)val);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i++) {
            result.push_back(rec_(i));
        }
        return result;
    }
};
