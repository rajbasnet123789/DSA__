class Solution {
public:
   
    int solve(string &s,int i,int j){
          if(i>j){
             return 0;
          }
          if(s[i]==s[j]){
              return solve(s,i+1,j-1);
          }
          else{
             int take_i=1+solve(s,i+1,j);
             int take_j=1+solve(s,i,j-1);
             return min(take_i,take_j);
          }
    }
    int minInsertions(string s) {
       return solve(s,0,s.length()-1);
    }
};

class Solution {
public:
   int dp[501][501];
    int solve(string &s,int i,int j){
          if(i>j){
             return 0;
          }
          if(dp[i][j]!=-1){
            return dp[i][j];
          }
          if(s[i]==s[j]){
              return dp[i][j]=solve(s,i+1,j-1);
          }
          else{
             int take_i=1+solve(s,i+1,j);
             int take_j=1+solve(s,i,j-1);
             return dp[i][j]=min(take_i,take_j);
          }
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
       return solve(s,0,s.length()-1);
    }
};