class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Base length check
        if (m + n != s3.length()) {
            return false;
        }
        
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // Initialize first column (using s1 only)
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        
        // Initialize first row (using s2 only) - THIS WAS MISSING
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool from_s1 = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool from_s2 = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[i][j] = from_s1 || from_s2;
            }
        }
        
        return dp[m][n];
    }
};