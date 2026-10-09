#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<string, vector<int>> memo;

public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        std::vector<int> results;
        bool isNumber = true;

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;
                
                // Divide and conquer: compute left and right sub-expressions
                std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine results based on the current operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') results.push_back(l + r);
                        else if (c == '-') results.push_back(l - r);
                        else if (c == '*') results.push_back(l * r);
                    }
                }
            }
        }

        // Base case: if the string is just a number, convert it and return
        if (isNumber) {
            results.push_back(std::stoi(expression));
        }

        return memo[expression] = results;
    }
};