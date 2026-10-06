class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // Convert the dictionary to an unordered_set for O(1) lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] represents whether the substring s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty string
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // If the prefix s[0...j-1] is valid and the remaining substring s[j...i-1] is in the dictionary
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Found a valid break point, no need to check other splits for this i
                }
            }
        }
        
        return dp[n];
    }
};