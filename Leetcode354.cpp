class Solution {
public:
  
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
             if(a[0]==b[0]) return a[1]>b[1];
             return a[0]<b[0];
        });
        vector<int>height;
        for(auto it:envelopes){
              int h=it[1];
              height.push_back(h);
        }
        return lengthOfLIS(height);
    }
};