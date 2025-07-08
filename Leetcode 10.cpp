//Recursion
class Solution {
public:

    bool solve(string &s, string &p, int i, int j) {
        if (j == p.length()) {
            return i == s.length();
        }

        bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool skip = solve(s, p, i, j + 2);
            bool use = match && solve(s, p, i + 1, j);
            return skip || use;
        }

        if (match) {
            return solve(s, p, i + 1, j + 1);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};

//Memoization + recursion
class Solution {
public:
    int dp[21][21];

    bool solve(string &s, string &p, int i, int j) {
        if (j == p.length()) {
            return i == s.length();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool skip = solve(s, p, i, j + 2);
            bool use = match && solve(s, p, i + 1, j);
            return dp[i][j] = skip || use;
        }

        if (match) {
            return dp[i][j] = solve(s, p, i + 1, j + 1);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
};
