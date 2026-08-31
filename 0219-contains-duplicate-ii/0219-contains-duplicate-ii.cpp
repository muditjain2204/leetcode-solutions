#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            // Keep window size within k elements
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            // If already present in the current window of size k
            if (!window.insert(nums[i]).second) {
                return true;
            }
        }

        return false;
    }
};