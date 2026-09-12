class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        for(int x : nums){
            if(x ==0) 
            red++;
            else if(x == 1)
            white++;
            else blue++;
        }

        int index = 0;
        while(red--) 
        nums[index++] = 0;
        while(white--) 
        nums[index++] = 1;
        while(blue--) 
        nums[index++] = 2;
        
    }
};