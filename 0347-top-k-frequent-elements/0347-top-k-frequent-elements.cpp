class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> us;
        //count freq of each element 
        for(int num:nums){
            us[num]++;
        }

        //Bucket sort where index represent frequency
        //Maximum freq of any element is nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for(const auto& [num, freq]: us){
            buckets[freq].push_back(num);
        }

        //Iteraate from highest freq bucket down to lowest
        vector<int> result;
        for(int i=buckets.size() - 1; i>= 0 && result.size() < k; --i){
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size() == k)
                break;
            }
        }
        return result;

    }
};