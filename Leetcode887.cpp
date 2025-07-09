class Solution {
public:
    int dp[101][10001];

    int solve(int e, int f) {
        if (e == 1 || f == 0 || f == 1) {
            return f;
        }
        if (dp[e][f] != -1) {
            return dp[e][f];
        }

        int low = 1, high = f, mini = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            int left = solve(e - 1, mid - 1); // egg breaks
            int right = solve(e, f - mid);   // egg doesn't break

            int temp = 1 + max(left, right);
            mini = min(mini, temp);

            if (left < right) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return dp[e][f] = mini;
    }

    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};
