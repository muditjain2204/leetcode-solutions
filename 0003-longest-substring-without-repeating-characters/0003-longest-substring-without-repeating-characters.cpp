class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256,-1);

        int max_length = 0;
        int left = 0;

        for(int right=0; right<s.length(); ++right){
            char current = s[right];

            //if the character was seen inside the current window , move the left pointer
            if(last_seen[current] >= left){
                left = last_seen[current] + 1;
            }

            //update the last seen positopn of the character
            last_seen[current] = right;

            //calculate the current window length and update max_length
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};