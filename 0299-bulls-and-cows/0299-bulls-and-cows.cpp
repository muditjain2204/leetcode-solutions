class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> count(10, 0);

        for (int i = 0; i < secret.length(); i++) {
            char s = secret[i];
            char g = guess[i];

            if (s == g) {
                bulls++;
            } else {
                // If this secret digit was previously seen in guess, it's a cow
                if (count[s - '0'] < 0) {
                    cows++;
                }
                // If this guess digit was previously seen in secret, it's a cow
                if (count[g - '0'] > 0) {
                    cows++;
                }

                count[s - '0']++;
                count[g - '0']--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};