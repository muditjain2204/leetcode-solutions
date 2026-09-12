#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        if (min_val == max_val) return 0;

        // Bucket size must be at least 1
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        vector<int> min_bucket(bucket_count, INT_MAX);
        vector<int> max_bucket(bucket_count, INT_MIN);

        // Place each number into its corresponding bucket
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            min_bucket[idx] = min(min_bucket[idx], num);
            max_bucket[idx] = max(max_bucket[idx], num);
        }

        int max_gap = 0;
        int prev_max = min_val;

        // Gap between adjacent non-empty buckets
        for (int i = 0; i < bucket_count; ++i) {
            if (min_bucket[i] == INT_MAX) continue; // Skip empty buckets

            max_gap = max(max_gap, min_bucket[i] - prev_max);
            prev_max = max_bucket[i];
        }

        return max_gap;
    }
};