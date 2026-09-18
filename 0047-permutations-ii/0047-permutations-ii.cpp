class Solution {
public:

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current , vector<vector<int>>& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return ;
        }

        for(int i=0; i<nums.size(); i++){
            //skip if the element is already used in the current permutation
            if(used[i])
            continue;

            if(i>0 && nums[i] == nums[i-1] && !used[i-1])
            continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums,used,current,result);

            //backtrack
            current.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        //Sort to bring duplicate elements together
        sort(nums.begin(), nums.end());

        backtrack(nums, used, current, result);
        return result;
    }
};