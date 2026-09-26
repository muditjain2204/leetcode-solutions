class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        int prev2 = 1; // DP value for s[i-2]
        int prev1 = 1; // DP value for s[i-1]

        for (int i = 1; i < n; ++i) {
            int current = 0;

            // Single digit decoding (1-9)
            if (s[i] != '0') {
                current += prev1;
            }

            // Two digit decoding (10-26)
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};