class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       vector<int> result;

       int n = nums.size();
       int threshold = n/3;

       int i = 0;
       while(i<n){
        int count = 1;
        while(i+1<n && nums[i] == nums[i+1]){
            count++;
            i++;
        }
        if(count > threshold){
            result.push_back(nums[i]);
        }
        i++;
    
       }
       return result;
    }
};