#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Collect all critical points (events)
        // Store left edge height as negative to distinguish from right edge
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Start of building
            events.push_back({b[1], b[2]});  // End of building
        }
        
        // Sort events:
        // 1. By x-coordinate ascending
        // 2. If x is same, negative height comes before positive height (starts before ends)
        // 3. If both are starts, larger height comes first (-height is smaller)
        // 4. If both are ends, smaller height comes first
        sort(events.begin(), events.end());
        
        vector<vector<int>> result;
        multiset<int> heights = {0}; // Active building heights, grounded at 0
        int prev_max = 0;
        
        for (const auto& [x, h] : events) {
            if (h < 0) {
                heights.insert(-h); // Add building height
            } else {
                heights.erase(heights.find(h)); // Remove building height
            }
            
            int current_max = *heights.rbegin();
            // If the maximum height changes, record a key point
            if (current_max != prev_max) {
                result.push_back({x, current_max});
                prev_max = current_max;
            }
        }
        
        return result;
    }
};