class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] stores the minimum edit distance between 
        // word1[0...i-1] and word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base case: converting word1 prefixes to empty word2 requires deletions
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        // Base case: converting empty word1 to word2 prefixes requires insertions
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no new operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Take the minimum of Insert, Delete, or Replace + 1
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j],     // Delete
                        dp[i - 1][j - 1]  // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};