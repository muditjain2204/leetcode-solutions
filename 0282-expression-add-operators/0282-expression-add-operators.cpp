#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
    
private:
    void backtrack(const string& num, int target, int index, string path, long eval, long prev, vector<string>& result) {
        // Base case: if we have reached the end of the string, check if the expression evaluates to the target
        if (index == num.length()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = index; i < num.length(); ++i) {
            // Numbers cannot have leading zeros (e.g., "05" is invalid, but "0" is valid)
            if (i > index && num[index] == '0') {
                break;
            }
            
            string subStr = num.substr(index, i - index + 1);
            long curr = stol(subStr);
            
            if (index == 0) {
                // First number doesn't have an operator preceding it
                backtrack(num, target, i + 1, subStr, curr, curr, result);
            } else {
                // Try '+' operator
                backtrack(num, target, i + 1, path + "+" + subStr, eval + curr, curr, result);
                
                // Try '-' operator
                backtrack(num, target, i + 1, path + "-" + subStr, eval - curr, -curr, result);
                
                // Try '*' operator (handle precedence by removing 'prev' and adding 'prev * curr')
                backtrack(num, target, i + 1, path + "*" + subStr, eval - prev + prev * curr, prev * curr, result);
            }
        }
    }
};