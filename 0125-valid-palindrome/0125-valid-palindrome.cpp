class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer forward if not alphanumeric
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer backward if not alphanumeric
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};