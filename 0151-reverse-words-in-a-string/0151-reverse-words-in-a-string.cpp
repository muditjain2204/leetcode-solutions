#include <string>
#include <algorithm>
#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, result = "";
        
        // Extract words one by one, ignoring extra spaces
        while (ss >> word) {
            if (result == "") {
                result = word;
            } else {
                word = word + " ";
                result = word + result;
            }
        }
        
        return result;
    }
};