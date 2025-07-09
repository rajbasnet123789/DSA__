class Solution {
public:
    int dp[1001][1001];

    int solve(int l, int r, vector<int>& cuts) {
        if (r - l < 2) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int mini = INT_MAX;
        for (int k = l + 1; k < r; ++k) {
            int cost = (cuts[r] - cuts[l]) + solve(l, k, cuts) + solve(k, r, cuts);
            mini = min(mini, cost);
        }

        return dp[l][r] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        return solve(0, cuts.size() - 1, cuts);
    }
};
