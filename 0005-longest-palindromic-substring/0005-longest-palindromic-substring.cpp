class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) 
        return "";

        int start = 0;
        int maxLength = 0;

        for(int i=0; i<s.length(); i++){
            //check for odd length palindromes (center is s[i])
            expandAroundCenter (s, i,i, start,maxLength);

            //Check for even -length palindrome (center is between s[i] and s[i+1])

            expandAroundCenter(s,i,i+1,start,maxLength);
        }
        return s.substr(start, maxLength);
    }

    private:
     void expandAroundCenter(const string& s, int left, int right, int& start, int & maxLength){
        //Expands outwards as long as characters match and indices stay in bounds

        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        //Calculate the length of the valid palindrome found
        int currentLength = right - left - 1;

        //Update the maximum palindrome rnage if a longer one is found
        if(currentLength > maxLength){
            maxLength = currentLength;
            start = left + 1;
        }
     }
};