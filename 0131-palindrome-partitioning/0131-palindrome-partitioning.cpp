class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void backtrack(int startIndex, string& s, vector<string>& currentPath, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the results
        if (startIndex == s.length()) {
            result.push_back(currentPath);
            return;
        }

        for (int i = startIndex; i < s.length(); ++i) {
            // Check if the substring s[startIndex...i] is a palindrome
            if (isPalindrome(s, startIndex, i)) {
                currentPath.push_back(s.substr(startIndex, i - startIndex + 1)); // Choose
                backtrack(i + 1, s, currentPath, result);                        // Explore
                currentPath.pop_back();                                          // Un-choose (Backtrack)
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPath;
        backtrack(0, s, currentPath, result);
        return result;
    }
};