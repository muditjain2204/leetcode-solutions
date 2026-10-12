#include <string>
#include <numeric>

class Solution {
public:
    int calculate(std::string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        int currentNumber = 0;
        int lastNumber = 0;
        int result = 0;
        char lastOperator = '+';
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (std::isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            
            if ((!std::isdigit(c) && c != ' ') || i == n - 1) {
                if (lastOperator == '+') {
                    result += lastNumber;
                    lastNumber = currentNumber;
                } else if (lastOperator == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                } else if (lastOperator == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (lastOperator == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                
                lastOperator = c;
                currentNumber = 0;
            }
        }
        
        result += lastNumber;
        return result;
    }
};