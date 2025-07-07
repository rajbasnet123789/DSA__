class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int n=prices.size();
        int start=prices[0];
      for(int i=1;i<n;i++){
        if(start<prices[i]){
            max_profit+=prices[i]-start;
        }
        start=prices[i];
      }
      return max_profit;
    }
};