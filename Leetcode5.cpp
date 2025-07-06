
//NAIVES :tc: 0(N^3)  sc:0(1)
class Solution {
public:
   bool isplaindrome(string s){
       for(int i=0,j=s.length()-1;i<j;i++,j--){
           if(s[i]!=s[j]){
            return false;
           }
       }
       return true;
   }
    string longestPalindrome(string s) {
        int maxlen=0;
        string result="";
        for(int i=0;i<s.length();i++){
              string t="";
              for(int j=i;j<s.length();j++){
                   t+=s[j];
                   int l=j-i+1;
                   if(isplaindrome(t) && maxlen<l){
                       maxlen=l;
                       result="";
                       result+=t;
                   }
              }
        }
        return result;
    }
};

//BETTER:tc: 0(N^2)  sc:0(N^2)

class Solution {
public:
   int dp[1001][1001];
   bool isplaindrome(string &s,int i,int j){//Pass by refernce or else it will give memory limit exceed as it will try to make copy and string is very large
         if(i>=j){
            return true;
         }
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
         if(s[i]==s[j]){
            return dp[i][j]=isplaindrome(s,i+1,j-1);
         }
         else{
            return dp[i][j]=false;
         }
   }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int maxlen=0;
        int start=0;
        for(int i=0;i<s.length();i++){
              for(int j=i;j<s.length();j++){
                   int l=j-i+1;
                   if(isplaindrome(s,i,j) && maxlen<l){
                       maxlen=l;
                       start=i;
                   }
              }
        }
        return s.substr(start,maxlen);
    }
};


//Best: tc:0(N^2) sc:0(N)

class Solution {
public:
   int dp[1001][1001];
    string longestPalindrome(string s) {
        int n=s.length();
        if(s.length()==1){
            return s;
        }
           for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
  
        int maxlen=1;
        int start=0;
      
        for(int L=2;L<=s.length();L++){
              for(int i=0;i<n-L+1;i++){
                   int j=i+L-1;
                   if(s[i]==s[j] && L==2){
                     dp[i][j]=true;
                     maxlen=max(maxlen,j-i+1);
                     start=i;
                   }
                   else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                     maxlen=max(maxlen,j-i+1);
                     start=i;
                   }
                   else{
                      dp[i][j]=false;
                   }

              }
        }
        return s.substr(start,maxlen);
    }
};