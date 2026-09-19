class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) 
        return {};
        sort(nums.begin() , nums.end());

        //dp{i] sotres the size of the largest divisible subset ending at nums[i]
        vector<int> dp(n,1);

        //parent[i] stores the index of the previous element in the subset
        vector<int> parent(n,-1);

        int max_size = 1;
        int max_index = 0;

        for(int i=0; i< n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > max_size){
                max_size = dp[i];
                max_index = i;
            }
        }

        vector<int> result;
        int curr = max_index;
        while(curr != -1){
            result.push_back(nums[curr]);
            curr = parent[curr];
        }

        return result;



    }
};