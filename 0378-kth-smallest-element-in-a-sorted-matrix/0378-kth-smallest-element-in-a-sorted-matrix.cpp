class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low<high){
            int mid = low + (high-low)/2;

            //count elements less than or equal to mid
            if(countLessEqual(matrix, mid,n)<k){
                low = mid + 1;
            }else {
                high = mid;
            }

        }

        return low;
    }

    private:
         int countLessEqual(const vector<vector<int>>& matrix, int target, int n){
            int count = 0;
            int row = n-1;
            int col = 0;

            //Traverse from the bottom-left corner to the top-right
            while(row >= 0 && col < n){
                if(matrix[row][col] <= target){
                    count += (row + 1);//all elements above in this column are also <= target
                    col++;
                }else{
                    row--;
                }
            }
            return count ;
         }
};