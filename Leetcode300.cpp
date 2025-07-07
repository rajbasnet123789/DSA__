class Solution {
public:
    int rec_(vector<int>& nums, int i, int prev_index) {
        if (i == nums.size()) return 0;
        int not_take = rec_(nums, i + 1, prev_index);
        int take = 0;
        if (prev_index == -1 || nums[i] > nums[prev_index]) {
            take = 1 + rec_(nums, i + 1, i);
        }
        return max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        return rec_(nums, 0, -1);
    }
};



class Solution {
public:
    int dp[2501][2501];

    int rec_(vector<int>& arr, int i, int prev_indx) {
        if (i == arr.size()) return 0;

        if (dp[i][prev_indx + 1] != -1) return dp[i][prev_indx + 1];

        int not_take = rec_(arr, i + 1, prev_indx);
        int take = 0;
        if (prev_indx == -1 || arr[i] > arr[prev_indx]) {
            take = 1 + rec_(arr, i + 1, i);
        }

        return dp[i][prev_indx + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec_(nums, 0, -1);
    }
};
