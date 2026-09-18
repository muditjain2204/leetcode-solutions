class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int left  = (n-1)/2; //end of the smllest half
        int right = n -1;//end of the largest half

        for(int i=0; i<n; i++){
            if(i%2 == 1){
                nums[i] = sorted[right--];
            }else {
                nums[i] = sorted[left--];
            }
        }
    }
};