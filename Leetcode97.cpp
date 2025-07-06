
//NAIVES SOLUTIon
class Solution {
public: 
   
   bool recur_(string &s1,string &s2,int i,int j,int k,string &s3){
       if(k==s3.length()){
        return true;
       }
       bool a=false,b=false;
       if(i<s1.length() && s1[i]==s3[k]){
          b=recur_(s1,s2,i+1,j,k+1,s3);
       }
       if(j<s2.length() && s2[j]==s3[k]){
             a=recur_(s1,s2,i,j+1,k+1,s3);
       }
       return a||b;
   }
   
    bool isInterleave(string s1, string s2, string s3) {
         int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;
        return recur_(s1,s2,0,0,0,s3);

    }
};

//Better approach

class Solution {
public: 
   int dp[101][101];
   bool recur_(string &s1,string &s2,int i,int j,int k,string &s3){
       if(k==s3.length()){
        return true;
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
       bool a=false,b=false;
       if(i<s1.length() && s1[i]==s3[i+j]){
          b=recur_(s1,s2,i+1,j,i+j+1,s3);
       }
       if(j<s2.length() && s2[j]==s3[i+j]){
             a=recur_(s1,s2,i,j+1,i+j+1,s3);
       }
       return dp[i][j]=a||b;
   }
   
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
         int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;
        return recur_(s1,s2,0,0,0,s3);

    }
};



//Best 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;

        bool dp[101][101] = {}; 
        dp[0][0] = true;

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i - 1][j];

                if (j > 0 && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }

        return dp[n1][n2];
    }
};
