#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap to keep track of the top k largest elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element
            }
        }
        
        return minHeap.top(); // The k-th largest element
    }
};