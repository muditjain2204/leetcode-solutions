#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string dir;
        
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(dir);
            }
        }
        
        std::string result = "";
        for (const std::string& s : stack) {
            result += "/" + s;
        }
        
        return result.empty() ? "/" : result;
    }
};